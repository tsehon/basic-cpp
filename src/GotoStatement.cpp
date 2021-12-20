#include "GotoStatement.h"
#include "ProgramState.h"
using namespace std;

GotoStatement::GotoStatement(int linenum)
	: m_linenum( linenum )
{}


void GotoStatement::execute(ProgramState * state, ostream &outf)
{
	state->updateNextLine(m_linenum);
	state->goNextLine();
}
