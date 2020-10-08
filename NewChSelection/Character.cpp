#include "Character.h"


//传private值
string Character::GetName() {
	return this->m_name;
}
int Character::GetAtk() {
	return this->m_atk;
}
int Character::GetDef() {
	return this->m_def;
}
int Character::GetNo() {
	return this->m_no;
}

//改private值
void Character::SetName(string name) {
	m_name = name;
}
void Character::SetAtk(int atk) {
	m_atk = atk;
}
void Character::SetDef(int def) {
	m_def = def;
}
void Character::SetNo(int i) {
	m_no = i;
}


void Hero::SetAtk(int atk) {
	Character::SetAtk(atk + equipAtk);
}
void Hero::SetDef(int def) {
	Character::SetDef(def + equipDef);
}