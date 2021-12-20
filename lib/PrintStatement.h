#ifndef PRINT_STATEMENT_INCLUDED
#define PRINT_STATEMENT_INCLUDED

#include "Statement.h"
#include <iostream>
#include "ProgramState.h"

class PrintStatement: public Statement
{
public:
	PrintStatement(std::string variableName);
	virtual void execute(ProgramState * state, std::ostream &outf);

private:
	std::string m_variableName;
};

#endif
