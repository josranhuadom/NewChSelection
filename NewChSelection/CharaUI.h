#pragma once
#include"List.h"
#include "InputChecking.h"

class CharaUI
{
public:
	int Menu();
	
	void CharaAdd(class CharacterList<Character>, struct Node<Character>*);
	void CharaModify(class CharacterList<Character>, struct Node<Character>*);
	void CharaRemove(class CharacterList<Character>, struct Node<Character>*);
	void CharaPrint(class CharacterList<Character>, struct Node<Character>*);
	void CharaWrongInput(class CharacterList<Character>, struct Node<Character>*);
};

