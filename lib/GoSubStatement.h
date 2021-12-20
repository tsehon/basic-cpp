#include "Statement.h"
#include "ProgramState.h"

class GoSubStatement: public Statement
{
public:
	GoSubStatement(int linenum);
	virtual void execute(ProgramState * state, std::ostream &outf);

private:
	int m_linenum;
};

