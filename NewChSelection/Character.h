#pragma once

#include<iostream>
#include<string>
using namespace std;

class Character
{
private:
	string m_name;
	int m_atk = 0;
	int m_def = 0;
	int m_no = 0;

public:

	//传private值
	string GetName();
	int GetAtk();
	int GetDef();
	int GetNo();

	//改private值
	void SetName(string);
	virtual void SetAtk(int);
	virtual void SetDef(int);
	void SetNo(int);
};

class Hero : public Character {
private:
	int equipAtk = 3;
	int equipDef = 3;

public:
	void SetAtk(int);
	void SetDef(int);
};

class Slave : public Character {};

