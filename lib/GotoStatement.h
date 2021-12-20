#include "Statement.h"
#include "ProgramState.h"

class GotoStatement: public Statement
{
public:
	GotoStatement(int linenum);
	virtual void execute(ProgramState * state, std::ostream &outf);

private:
	int m_linenum;
};
