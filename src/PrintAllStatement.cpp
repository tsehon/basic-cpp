// PrintAllStatement.cpp:
#include "ProgramState.h"
#include "PrintAllStatement.h"
using namespace std;

PrintAllStatement::PrintAllStatement()
{}


void PrintAllStatement::execute(ProgramState * state, ostream &outf)
{
	state->toStreamAll(outf);
	state->updateNextLine(state->getCurrLine()+1);
	state->goNextLine();
}
