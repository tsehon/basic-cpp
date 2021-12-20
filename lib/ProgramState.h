// ProgramState.h
//
// CS 104 / Fall 2021
//
// The ProgramState class encapsulates the state of an executing Facile
// program.  The state of a BASIC program consists of three parts:
//
//    * The program counter, which specifies the line number of the
//      statement that will execute next.
//    * A map, as explained by the problem writeup.
//    * A stack of integers, which is used to hold return lines for GOSUB
//      statements.
//
// We've provided you a start on this class, but you'll need to add methods
// to it as you go along.  In particular, you'll need methods to access and
// modify the state; these methods will be called primarily by the various
// execute() methods in the Statement subclasses, to allow the execution of
// a statement to change the state of a program.  For example, executing a
// GOTO statement will cause the program counter to be changed.

#ifndef PROGRAM_STATE_INCLUDED
#define PROGRAM_STATE_INCLUDED
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

class ProgramState
{
public:
	ProgramState(int numLines);
	
	void updateVal(std::string varName, int newVal); // updates a variables value
	int getVal(std::string varName); // returns the value of the given variable 
	void toStream(std::string var, std::ostream& outf); // prints the var and its value to a file
	void toStreamAll(std::ostream& outf);
	int getCurrLine();
	void goNextLine();
	void updateNextLine(int nextLine);
	int getReturnLine();
	void addReturnLine(int linenum);
	void endProgram();
	bool isOver();

private:
	int m_numLines;
      	bool m_over; // true if program is over	
	int m_line;
	int m_nextLine; // tracks the next line to execute
	std::map<std::string, int> m_varMap; // tracks all variables and associated integer values
	std::stack<int> m_stack; // holds return-to lines for gosub statements
};
#endif
