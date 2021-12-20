#include "Statement.h"
#include "ProgramState.h"

class ReturnStatement: public Statement
{
public:
	ReturnStatement();
	virtual void execute(ProgramState * state, std::ostream &outf);

};

