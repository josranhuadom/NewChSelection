#pragma once
#include"Character.h"
#include "Node.h"
#include "InputChecking.h"

#include <iostream>
using namespace std;


template <typename T>
class BaseList {
public:
    virtual void Print(struct Node <T>*);
    //virtual void Add(Character*, struct Node <Character>*);
    //virtual void Remove(int, struct Node <Character>*);
    //virtual void Modify(int, struct Node <Character>*);
    virtual int DetectExist(struct Node <T>*);


    //CharacterNode* Get(unsigned); �����ã�
//unsigned Size();�����ã�
};

//��ɫ����ר�ú���
template <typename T>
class CharacterList :public BaseList<T> {
public:
    void Print(struct Node <Character>*);
    void Add(Character Ch, struct Node <Character>*);
    void Remove(int, struct Node <Character>*);
    void Modify(int, struct Node <Character>*);
    int DetectExist(struct Node <Character>*);
};

//��������ר�ú���
template <typename T>
class NumList :public BaseList<T> {
public:
    void Print(struct Node <int>*);
    void Add(int, struct Node <int>*);
    void Remove(int, struct Node <int>*);
    void Modify(int, struct Node <int>*);
    int DetectExist(struct Node <int>*);
};


//����
//����
template <typename T>
void BaseList<T>::Print(struct Node <T>* n) {}

template <typename T>
int BaseList<T>::DetectExist(struct Node <T>* n) {
    if (!n->Next) {
        cout << "û���κν�ɫ��\n";
        cout << endl;
        return 1;
    }
    else return 0;
}

//��ɫ����
template <typename T>
void CharacterList<T>::Print(struct Node <Character>* n) {
    int i = 1;
    struct Node <Character>* Current = n->Next;
    while (Current) {
        cout << i << "��"
            << "���֣�" << Current->Data.GetName() << "\n"
            << "   ��������" << Current->Data.GetAtk() << "\n"
            << "   ��������" << Current->Data.GetDef() << "\n" << endl;

        Current = Current->Next;
        i++;
    }
    return;
}

    //����ָ���Ƿ���Σ�գ�
template <typename T>
void CharacterList<T>::Add(Character Ch, struct Node <Character>* n) {
    int i = 1;
    //TҪ��Ҫ�ĳ�Character
    struct Node <T>* Current = n;
    while (Current->Next) {
        Current = Current->Next;
        i++;
    }
    Current->Next = new struct Node<T>;
    Current->Next->Next = NULL;
    Current->Next->Data = Ch;

    Current->Next->Data.SetNo(i);
}

template <typename T>
void CharacterList<T>::Remove(int no, struct Node <Character>* n) {
    struct Node<T>* Current = n;
    while (Current->Next) {
        int i = Current->Next->Data.GetNo();
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
    struct Node<T>* Current = n->Next;
    while (Current) {
        int i = Current->Data.GetNo();
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
                cout << "�����������ƣ�"; cin >> name; Current->Data.SetName(name);
                cout << "��������Ϊ��" << Current->Data.GetName() << endl;
                break;
            }
            case 2:
            {
                int atk;
                do {
                    cout << "�������¹�������"; cin >> atk;
                } while (InputChecking(atk));

                Current->Data.SetAtk(atk);
                cout << "���ڹ�����Ϊ��" << Current->Data.GetAtk() << endl;
                break;
            }
            case 3:
            {
                int def;
                do {
                    cout << "�������·�������"; cin >> def;
                } while (InputChecking(def));

                Current->Data.SetDef(def);
                cout << "���ڷ�����Ϊ��" << Current->Data.GetDef() << endl;
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
    if (!n->Next) {
        cout << "û���κν�ɫ��\n";
        cout << endl;
        return 1;
    }
    else return 0;
}


//��������
template <typename T>
void NumList<T>::Print(struct Node <int>* n) {
    struct Node <T>* Current = n->Next;
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
    struct Node<T>* Current = n->Next;
    while (Current) {
        if (Current->Data == modinum) {
            cout << "�����������֣�";
            int NewNum; cin >> NewNum;
            Current->Data = NewNum;
            return;
        }
        Current = Current->Next;
    }
    cout << "�����ڸ����֣��˻���������\n" << endl;
    return;
}

template <typename T>
int NumList<T>::DetectExist(struct Node <int>* n) {
    if (!n->Next) {
        cout << "û���κν�ɫ��\n";
        cout << endl;
        return 1;
    }
    else return 0;
}