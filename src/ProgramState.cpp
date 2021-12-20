#include "ProgramState.h"
using namespace std;

ProgramState::ProgramState(int numLines){
	m_numLines = numLines;
	m_nextLine = 1;
	m_line = 0;
	m_over = 0;
}

void ProgramState::updateVal(std::string var, int val){
	if (m_varMap.count(var) > 0){
		m_varMap[var] = val;
	} else {
		m_varMap.insert(std::pair<string, int>(var, val));
	}
}

int ProgramState::getVal(std::string var){
	return m_varMap.at(var);
}

void ProgramState::toStream(std::string var, std::ostream& outf){
	map<std::string, int>::iterator it = m_varMap.find(var);
	outf << it->first << " : " << it->second << std::endl;	
}

void ProgramState::toStreamAll(std::ostream &outf){
	map<std::string, int>::iterator it;
	
	for (it = m_varMap.begin(); it != m_varMap.end(); it++){
		outf << it->first << " : " << it->second << std::endl;
	}
}

int ProgramState::getCurrLine(){
	return m_line;
}

void ProgramState::goNextLine(){
	m_line = m_nextLine;
}

void ProgramState::updateNextLine(int val){
	m_nextLine = val;
}

int ProgramState::getReturnLine(){
	int temp = m_stack.top();
	m_stack.pop();
	return temp;
}

void ProgramState::addReturnLine(int val){
	m_stack.push(val);
}

void ProgramState::endProgram(){
	m_over = 1;
}

bool ProgramState::isOver(){
	if (m_over) {
		return true;
	} 
	return false;
}
