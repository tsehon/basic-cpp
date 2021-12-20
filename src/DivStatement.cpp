#include "DivStatement.h"
#include "ProgramState.h"
using namespace std;

DivStatement::DivStatement(std::string variableName, int value) : m_variableName(variableName), m_value(value)
{}

void DivStatement::execute(ProgramState* state, ostream &outf)
{
	int curr = state->getVal(m_variableName);
	m_value = curr/m_value;
	state->updateVal(m_variableName, m_value);
	state->updateNextLine(state->getCurrLine()+1);
	state->goNextLine();
}
