#include "GoSubStatement.h"
#include "ProgramState.h"
using namespace std;

GoSubStatement::GoSubStatement(int linenum)
	: m_linenum( linenum )
{}


void GoSubStatement::execute(ProgramState * state, ostream &outf)
{
	state->addReturnLine(state->getCurrLine());
	state->updateNextLine(m_linenum);
	state->goNextLine();
}
