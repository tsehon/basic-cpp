// LetStatement.cpp:
#include "LetStatement.h"
#include "ProgramState.h"

using namespace std;

LetStatement::LetStatement(std::string variableName, int value)
	: m_variableName( variableName ), m_value( value )
{}


// The LetStatement version of execute() should make two changes to the
// state of the program:
//
//    * set the value of the appropriate variable
//    * increment the program counter
void LetStatement::execute(ProgramState* state, ostream &outf)
{
	state->updateVal(m_variableName, m_value);
	state->updateNextLine(state->getCurrLine()+1);
	state->goNextLine();
}
