#include "Statement.h"
#include "ProgramState.h"

class IfStatement: public Statement
{
public:
	IfStatement(std::string variableName, int value, std::string op, int linenum);
	virtual void execute(ProgramState * state, std::ostream &outf);

private:
	std::string m_variableName;
	int m_value;
	std::string m_op;
	int m_linenum;
};

