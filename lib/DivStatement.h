
#include "Statement.h"
#include "ProgramState.h"

class DivStatement: public Statement
{
public:
	DivStatement(std::string var, int val);
	virtual void execute(ProgramState* state, std::ostream& outf);

private:
	std::string m_variableName;
	int m_value;
};
