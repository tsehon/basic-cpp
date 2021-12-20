#include "ReturnStatement.h"
#include "ProgramState.h"
using namespace std;

ReturnStatement::ReturnStatement()
{}


void ReturnStatement::execute(ProgramState * state, ostream &outf)
{
	int nextline = state->getReturnLine();
	state->updateNextLine(nextline);
	state->goNextLine();
}
