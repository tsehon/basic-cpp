#include "AddStatement.h"
#include "ProgramState.h"
using namespace std;

AddStatement::AddStatement(std::string variableName, int value) : m_variableName(variableName), m_value(value)
{}

void AddStatement::execute(ProgramState* state, ostream &outf)
{
	int curr = state->getVal(m_variableName);
	m_value += curr;
	state->updateVal(m_variableName, m_value);
	state->updateNextLine(state->getCurrLine()+1);
	state->goNextLine();
}
