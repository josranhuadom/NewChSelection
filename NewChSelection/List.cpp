#include "List.h"
using namespace std;

//����
/*template <typename T>
void BaseList<T>::Print(struct Node <T>* n){}

template <typename T>
void BaseList<typename T>::Add(Character*, struct Node <T>*) {}

template <typename T>
void BaseList<typename T>::Remove(int, struct Node <T>*) {}

template <typename T>
void BaseList<typename T>::Modify(int, struct Node <Character>*) {}

template <typename T>
int BaseList<T>::DetectExist(struct Node <T>* n) {
    if (!n->Next) {
        cout << "û���κν�ɫ��\n";
        cout << endl;
        return 1;
    }
    else return 0;
}*/

//��ɫ����ר�ú���
/*template <typename T>
void CharacterList<T>::Print(struct Node <Character>* n) {
    int i = 1;
    struct Node <Character>* Current = n->next;
    while (Current) {
        cout << i << "��"
            << "���֣�" << Current->Data.GetName()<< "\n"
            << "   ��������" << Current->Data.GetAtk() << "\n"
            << "   ��������" << Current->Data.GetDef() << "\n" << endl;

        Current = Current->next;
        i++;
    }
    return;
}

template <typename T>
void CharacterList<T>::Add(Character* Ch, struct Node <Character>* n) {
    int i = 1;
    //TҪ��Ҫ�ĳ�Character
    struct Node <T>* Current = n;
    while (Current->next) {
        Current = Current->next;
        i++;
    }
    Current->next = new struct Node<T>;
    Current->next->next = NULL;
    Current->next->Data = Ch;

    Current->next->Data.SetNo(i);
}

template <typename T>
void CharacterList<T>::Remove(int no, struct Node <Character>* n) {
    struct Node<T>* Current = n;
    while (Current->Next) {
        int i = Current->Next->Data->GetNo();
        if (i == no) {
            struct Node<T>* Next = Current->Next->Next;
            delete Current->Next;
            Current->Next = Next;
            return;
        }
        Current = Current->Next;
    }
    cout << "�����ڸý�ɫ���˻���������\n" << endl;
    return;
}

template <typename T>
void CharacterList<T>::Modify(int no, struct Node <Character>* n) {
    struct Node<T>* Current = n->next;
    while (Current) {
        int i = Current->Data->GetNo();
        if (i == no) {
            int Element = NULL;
            do {
                cout << "��������Ķ������ԣ�\n"
                    << "1. ���ƣ�2.��������3.������\n";
                cin >> Element;
            } while (InputChecking(Element));
            cout << endl;

            //������ҵ�ѡ�����Ķ���������֮һ
            switch (Element)
            {
            case 1:
            {
                string name;
                cout << "�����������ƣ�"; cin >> name; Current->Data->SetName(name);
                cout << "��������Ϊ��" << Current->Data->GetName() << endl;
                break;
            }
            case 2:
            {
                int atk;
                do {
                    cout << "�������¹�������"; cin >> atk;
                } while (InputChecking(atk));

                Current->Data->SetAtk(atk);
                cout << "���ڹ�����Ϊ��" << Current->Data->GetAtk() << endl;
                break;
            }
            case 3:
            {
                int def;
                do {
                    cout << "�������·�������"; cin >> def;
                } while (InputChecking(def));

                Current->Data->SetDef(def);
                cout << "���ڷ�����Ϊ��" << Current->Data->GetDef() << endl;
                break;
            }
            default:
                cout << "����������" << endl;
                break;
            }
        }
        else {
            Current = Current->Next;
            if (!Current) {
                cout << "�����ڸý�ɫ���˳���������\n" << endl;
                return;
            }
        }

        int q;
        cout << endl << "�Ƿ��˳���\n1. ��\t2. ��"; cin >> q;
        if (q == 1)
            return;
        cout << endl;
    }
}

template <typename T>
int CharacterList<T>::DetectExist(struct Node <Character>* n) {

}


//��������ר�ú���
template <typename T>
void NumList<T>::Print(struct Node <int>* n) {
    struct Node <T>* Current = n->next;
    while (Current) {
        cout << Current->Data << "\n";
        Current = Current->Next;
    }
    cout << endl;
    return;
}

template <typename T>
void NumList<T>::Add(int newnum, struct Node <int>* n) {
    struct Node <T>* Current = n;
    while (Current->Next) {
        Current = Current->Next;
    }
    Current->Next = new struct Node<T>;
    Current->Next->Next = NULL;
    Current->Next->Data = newnum;
    return;
}

template <typename T>
void NumList<T>::Remove(int removenum, struct Node <int>* n) {
    struct Node<T>* Current = n;
    while (Current->Next) {
        if (Current->Next->Data == removenum) {
            struct Node<T>* Next = Current->Next->Next;
            delete Current->Next;
            Current->Next = Next;
            return;
        }
        Current = Current->Next;
    }
    cout << "�����ڸ����֣��˻���������\n" << endl;
    return;
}

template <typename T>
void NumList<T>::Modify(int modinum, struct Node <int>* n) {
    struct Node<T>* Current = n->next;
    while (Current) {
        if (Current->Data == modinum) {
            cout << "�����������֣�";
            int NewNum; cin >> NewNum;
            Current->Data = NewNum;
            return;
        }
        Current = Current->next;
    }
    cout << "�����ڸ����֣��˻���������\n" << endl;
    return;
}

template <typename T>
int NumList<T>::DetectExist(struct Node <int>* n) {
    if (!n->next) {
        cout << "û���κν�ɫ��\n";
        cout << endl;
        return 1;
    }
    else return 0;
}
*/