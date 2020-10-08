#include "NumUI.h"


int NumUI::NumMenu() {
	cout << "1. ��������\t2. �޸�����\t3. ɾ������\t4. ����һ��\n"
		<< "��ѡ�������";
	int i; cin >> i;

	return i;
}

void NumUI::NumAdd(class NumList<int> thelist, struct Node<int>* n) {
	cout << "���������֣�";
	int NewNum; cin >> NewNum;

	thelist.Add(NewNum, n); cout << endl;
	NumPrint(thelist, n); cout << endl;
	return;
}
void NumUI::NumModify(class NumList<int> thelist, struct Node<int>* n) {
	NumPrint(thelist, n); cout << endl;
	cout << "��������Ҫ���ĵ����֣�";
	int ModiNum; cin >> ModiNum;
	thelist.Modify(ModiNum, n);
	NumPrint(thelist, n); cout << endl;
	return;
}
void NumUI::NumRemove(class NumList<int> thelist, struct Node<int>* n) {
	NumPrint(thelist, n); cout << endl;
	cout << "��������Ҫɾ�������֣�";
	int RemoveNum; cin >> RemoveNum;
	thelist.Remove(RemoveNum, n);
	NumPrint(thelist, n); cout << endl;
	return;
}
void NumUI::NumPrint(class NumList<int> thelist, struct Node<int>* n) {
	cout << "�����������£�\n";
	thelist.Print(n);
	return;
}