#include "Statement.h"
#include "ProgramState.h"

class EndStatement : public Statement 
{
public:
	EndStatement();
	virtual void execute(ProgramState* state, std::ostream& outf);
};

