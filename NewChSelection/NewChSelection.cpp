#include"CharaUI.h"
#include "Node.h"
#include "InputChecking.h"
#include "List.h"
#include"Character.h"
#include"NumUI.h"
#include <iostream>

using namespace std;

int main(){
    struct Node <int>* n1;
    n1 = new struct Node <int>;
    n1->Next = NULL;
    NumList<int> numList;
    NumUI numui;


    struct Node<Character>* n2;
    n2 = new struct Node<Character>;
    n2 ->Next = NULL;
    CharacterList <Character> charaList;
    CharaUI charaui;

    int i;
    while (1) {
        do {
            cout << "1. 数字\t2. 角色\n"
                << "请问需要输入角色还是数字？\t";
            cin >> i;
        } while (InputChecking(i));

        //不是很清楚numList 和 charaList 要不要以指针的形式作为实参
        switch (i) {
            int select;
        case 1:
            select = numui.NumMenu();
            switch (select) {
            case 1:
                numui.NumAdd(numList, n1); break;
            case 2:
                numui.NumModify(numList, n1); break;
            case 3:
                numui.NumRemove(numList, n1); break;
            case 4:
                numui.NumPrint(numList, n1); break;
            default:
                cout << "不存在该选项，退回至主界面。\n"; cout << endl; break;
            }
            break;

        case 2:
            select = charaui.Menu();
            switch (select) {
            case 1:
                charaui.CharaAdd(charaList, n2); break;
            case 2:
                charaui.CharaModify(charaList, n2); break;
            case 3:
                charaui.CharaRemove(charaList, n2); break;
            case 4:
                charaui.CharaPrint(charaList, n2); break;
                //看看那个CharaWrongInput  和 CharacterNode* Get(unsigned); （备用）
                //和unsigned Size();（备用）能不能排上用场
            default:
                cout << "不存在该选项，退回至主界面。\n"; cout << endl; break;
            }
            break;

        default:
            cout << "不存在该选项，退回至主界面。\n"; cout << endl; break;
        }
    }

}


