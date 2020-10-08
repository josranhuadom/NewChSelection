#include "CharaUI.h"

int CharaUI::Menu() {
    cout << "欢迎来到角色管理系统。\n"
        << "1. 增加角色\t2. 编辑角色\t3. 删除角色\t4. 角色一览" << endl;

    int selection = NULL;
    do {
        cout << "请输入对应编号以选择操作: ";
        cin >> selection;
    } while (InputChecking(selection));

    return selection;
}

void CharaUI::CharaAdd(class CharacterList<Character> thelist, struct Node<Character>* n){
    string name; int atk; int def; int id;

    cout << "请输入角色名字："; cin >> name;

    do {
        cout << "请输入角色攻击力："; cin >> atk;
    } while (InputChecking(atk));

    do {
        cout << "请输入角色防御力："; cin >> def;
    } while (InputChecking(def));
    cout << endl;

    do {
        cout << "创建勇士还是奴隶？\n1.勇士\t2.奴隶："; cin >> id;
    } while (InputChecking(id));

    if (id == 1) {
        Hero Ch; Ch.SetName(name); Ch.SetAtk(atk); Ch.SetDef(def);
        thelist.Add(Ch, n);
    }
    else if (id == 2) {
        Slave Ch; Ch.SetName(name); Ch.SetAtk(atk); Ch.SetDef(def);
        thelist.Add(Ch, n);
    }
    else {
        cout << "输入错误，返回主菜单。" << endl;
    }
}

void CharaUI::CharaModify(class CharacterList<Character> thelist, struct Node<Character>* n) {
    if (thelist.DetectExist(n))
        return;
    else
    {
        cout << "\n以下是所有角色：\n";
        thelist.Print(n);
        cout << endl;

        int No;
        do {
            cout << "请输入想要改动的角色编号："; cin >> No;
        } while (InputChecking(No));

        thelist.Modify(No, n);
    }
    cout << endl;
    return;
}

void CharaUI::CharaRemove(class CharacterList<Character> thelist, struct Node<Character>* n) {
    if (thelist.DetectExist(n))
        return;
    else
    {
        cout << "\n以下是所有角色：\n";
        thelist.Print(n);
        cout << endl;

        int No;
        do {
            cout << "请输入想要删除的角色编号："; cin >> No;
        } while (InputChecking(No));

        thelist.Remove(No, n);//需要先解决增加角色时的编号问题
    }
    return;
}

void CharaUI::CharaPrint(class CharacterList<Character> thelist, struct Node<Character>* n) {
    if (thelist.DetectExist(n))
        return;
    else
        thelist.Print(n);

    return;
}

void CharaUI::CharaWrongInput(class CharacterList<Character> thelist, struct Node<Character>* n){
            cout << "错误输入，请重新输入\n" << endl;
}
