#pragma once

#include"List.h"

//using namespace std;

class NumUI
{
public:
	int NumMenu();

	void NumAdd(class NumList<int>, struct Node<int>*);
	void NumModify(class NumList<int>, struct Node<int>*);
	void NumRemove(class NumList<int>, struct Node<int>*);
	void NumPrint(class NumList<int>, struct Node<int>*);
};

