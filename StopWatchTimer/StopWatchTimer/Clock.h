#pragma once

class Clock {
public:
	virtual ~Clock(){}
	Clock(const char* p_Name):m_Name(p_Name){}
	virtual void Start() = 0;
private:
	const char* m_Name;
};