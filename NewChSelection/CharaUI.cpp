#include "CharaUI.h"

int CharaUI::Menu() {
    cout << "��ӭ������ɫ����ϵͳ��\n"
        << "1. ���ӽ�ɫ\t2. �༭��ɫ\t3. ɾ����ɫ\t4. ��ɫһ��" << endl;

    int selection = NULL;
    do {
        cout << "�������Ӧ�����ѡ�����: ";
        cin >> selection;
    } while (InputChecking(selection));

    return selection;
}

void CharaUI::CharaAdd(class CharacterList<Character> thelist, struct Node<Character>* n){
    string name; int atk; int def; int id;

    cout << "�������ɫ���֣�"; cin >> name;

    do {
        cout << "�������ɫ��������"; cin >> atk;
    } while (InputChecking(atk));

    do {
        cout << "�������ɫ��������"; cin >> def;
    } while (InputChecking(def));
    cout << endl;

    do {
        cout << "������ʿ����ū����\n1.��ʿ\t2.ū����"; cin >> id;
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
        cout << "������󣬷������˵���" << endl;
    }
}

void CharaUI::CharaModify(class CharacterList<Character> thelist, struct Node<Character>* n) {
    if (thelist.DetectExist(n))
        return;
    else
    {
        cout << "\n���������н�ɫ��\n";
        thelist.Print(n);
        cout << endl;

        int No;
        do {
            cout << "��������Ҫ�Ķ��Ľ�ɫ��ţ�"; cin >> No;
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
        cout << "\n���������н�ɫ��\n";
        thelist.Print(n);
        cout << endl;

        int No;
        do {
            cout << "��������Ҫɾ���Ľ�ɫ��ţ�"; cin >> No;
        } while (InputChecking(No));

        thelist.Remove(No, n);//��Ҫ�Ƚ�����ӽ�ɫʱ�ı������
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
            cout << "�������룬����������\n" << endl;
}
