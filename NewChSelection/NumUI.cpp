#include "NumUI.h"


int NumUI::NumMenu() {
	cout << "1. 增加数字\t2. 修改数字\t3. 删除数字\t4. 数字一览\n"
		<< "请选择操作：";
	int i; cin >> i;

	return i;
}

void NumUI::NumAdd(class NumList<int> thelist, struct Node<int>* n) {
	cout << "请输入数字：";
	int NewNum; cin >> NewNum;

	thelist.Add(NewNum, n); cout << endl;
	NumPrint(thelist, n); cout << endl;
	return;
}
void NumUI::NumModify(class NumList<int> thelist, struct Node<int>* n) {
	NumPrint(thelist, n); cout << endl;
	cout << "请输入想要更改的数字：";
	int ModiNum; cin >> ModiNum;
	thelist.Modify(ModiNum, n);
	NumPrint(thelist, n); cout << endl;
	return;
}
void NumUI::NumRemove(class NumList<int> thelist, struct Node<int>* n) {
	NumPrint(thelist, n); cout << endl;
	cout << "请输入想要删除的数字：";
	int RemoveNum; cin >> RemoveNum;
	thelist.Remove(RemoveNum, n);
	NumPrint(thelist, n); cout << endl;
	return;
}
void NumUI::NumPrint(class NumList<int> thelist, struct Node<int>* n) {
	cout << "所有数字如下：\n";
	thelist.Print(n);
	return;
}