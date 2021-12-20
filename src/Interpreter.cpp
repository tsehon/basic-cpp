// Interpreter.cpp
#include "Statement.h"
#include "ProgramState.h"
#include "LetStatement.h"
#include "AddStatement.h"
#include "GotoStatement.h"
#include "GoSubStatement.h"
#include "DivStatement.h"
#include "MultStatement.h"
#include "EndStatement.h"
#include "IfStatement.h"
#include "PrintAllStatement.h"
#include "PrintStatement.h"
#include "ReturnStatement.h"

#include <vector>
#include <string>
#include <sstream> 
#include <fstream>


using namespace std;

// parseProgram() takes a filename as a parameter, opens and reads the
// contents of the file, and returns an vector of pointers to Statement.
void parseProgram(istream& inf, vector<Statement *> & program);

// parseLine() takes a line from the input file and returns a Statement
// pointer of the appropriate type.  This will be a handy method to call
// within your parseProgram() method.
Statement * parseLine(string line);

// interpretProgram() reads a program from the given input stream
// and interprets it, writing any output to the given output stream.
// Note:  you are required to implement this function!
void interpretProgram(istream& inf, ostream& outf);


int main()
{
        cout << "Enter BASIC program file name: ";
        string filename;
        getline(cin, filename);
        ifstream infile(filename.c_str());
        if (!infile)
        {
                cout << "Cannot open " << filename << "!" << endl;
                return 1;
        }
        interpretProgram(infile, cout);
}



void parseProgram(istream &inf, vector<Statement *> & program)
{
	program.push_back(NULL);
	
	string line;
	while( ! inf.eof() )
	{
		getline(inf, line);
		program.push_back( parseLine( line ) );
	}
}


Statement* parseLine(string line)
{
	Statement * statement;	
	stringstream ss;
	string type;
	string var;
	string op;
	int val;
	int linenum;

	ss << line;
	ss >> type;
	
	if ( type == "LET" ) {
		ss >> var;
		ss >> val;
		statement = new LetStatement(var, val);
	} else if (type == "PRINT") {
		ss >> var;
		statement = new PrintStatement(var);
	} else if (type == "PRINTALL") {
		statement = new PrintAllStatement();
	} else if (type == "ADD") {
		ss >> var;
		ss >> val;
		statement = new AddStatement(var, val); 
	} else if (type == "SUB") {
		ss >> var;
		ss >> val;
		statement = new AddStatement(var, -val);
	} else if (type == "MULT") {
		ss >> var;
		ss >> val;
		statement = new MultStatement(var, val);
	} else if (type == "DIV") {
		ss >> var;
		ss >> val;
		statement = new DivStatement(var, val);
	} else if (type == "GOTO") {
		ss >> linenum;
		statement = new GotoStatement(linenum);
	} else if (type == "IF") {
		ss >> var;
		ss >> val;
		ss >> op;
	        ss >> linenum;
		statement = new IfStatement(var, val, op, linenum);	
	} else if (type == "GOSUB") {
		ss >> linenum;
		statement = new GoSubStatement(linenum);
	} else if (type == "RETURN") {
		statement = new ReturnStatement();
	} else {
		statement = new EndStatement();
	} 

	return statement;
}


void interpretProgram(istream& inf, ostream& outf)
{
	vector<Statement *> program;
	parseProgram( inf, program );
	
 	ProgramState* p = new ProgramState(program.size());

	while(program[p->getCurrLine()] != NULL){
		program[p->getCurrLine()]->execute(p, outf);
	}
}
