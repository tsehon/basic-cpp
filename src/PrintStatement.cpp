// PrintStatement.cpp:
#include "ProgramState.h"
#include "PrintStatement.h"
using namespace std;

PrintStatement::PrintStatement(std::string variableName)
	: m_variableName( variableName )
{}


void PrintStatement::execute(ProgramState * state, ostream &outf)
{
	state->toStream(m_variableName, outf);
	state->updateNextLine(state->getCurrLine()+1);
	state->goNextLine();
}
