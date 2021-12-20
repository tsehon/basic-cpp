#include "IfStatement.h"
#include "ProgramState.h"
using namespace std;

IfStatement::IfStatement(std::string variableName, int value, std::string op, int linenum)
	: m_variableName(variableName), m_value(value), m_op(op), m_linenum( linenum )
{}


void IfStatement::execute(ProgramState * state, ostream &outf)
{
	int curr = state->getVal(m_variableName);
	state->updateNextLine(state->getCurrLine()+1);

	if ((m_op == "<" && curr < m_value) || (m_op == "<=" && curr <= m_value) || 
		       (m_op == "<>" && curr != m_value) || (m_op == ">" && curr > m_value) ||
	       (m_op == ">=" && curr >= m_value) || (m_op == "=" && curr == m_value))
	{
		state->updateNextLine(m_linenum);
	} 
	state->goNextLine();
}
