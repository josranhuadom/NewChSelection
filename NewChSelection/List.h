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


    //CharacterNode* Get(unsigned); （备用）
//unsigned Size();（备用）
};

//角色链表专用函数
template <typename T>
class CharacterList :public BaseList<T> {
public:
    void Print(struct Node <Character>*);
    void Add(Character Ch, struct Node <Character>*);
    void Remove(int, struct Node <Character>*);
    void Modify(int, struct Node <Character>*);
    int DetectExist(struct Node <Character>*);
};

//数字链表专用函数
template <typename T>
class NumList :public BaseList<T> {
public:
    void Print(struct Node <int>*);
    void Add(int, struct Node <int>*);
    void Remove(int, struct Node <int>*);
    void Modify(int, struct Node <int>*);
    int DetectExist(struct Node <int>*);
};


//定义
//基类
template <typename T>
void BaseList<T>::Print(struct Node <T>* n) {}

template <typename T>
int BaseList<T>::DetectExist(struct Node <T>* n) {
    if (!n->Next) {
        cout << "没有任何角色。\n";
        cout << endl;
        return 1;
    }
    else return 0;
}

//角色链表
template <typename T>
void CharacterList<T>::Print(struct Node <Character>* n) {
    int i = 1;
    struct Node <Character>* Current = n->Next;
    while (Current) {
        cout << i << "："
            << "名字：" << Current->Data.GetName() << "\n"
            << "   攻击力：" << Current->Data.GetAtk() << "\n"
            << "   防御力：" << Current->Data.GetDef() << "\n" << endl;

        Current = Current->Next;
        i++;
    }
    return;
}

    //不用指针是否有危险？
template <typename T>
void CharacterList<T>::Add(Character Ch, struct Node <Character>* n) {
    int i = 1;
    //T要不要改成Character
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
    cout << "不存在该角色，退回至主界面\n" << endl;
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
                cout << "请问你想改动的属性：\n"
                    << "1. 名称；2.攻击力；3.防御力\n";
                cin >> Element;
            } while (InputChecking(Element));
            cout << endl;

            //根据玩家的选择来改动三个属性之一
            switch (Element)
            {
            case 1:
            {
                string name;
                cout << "请输入新名称："; cin >> name; Current->Data.SetName(name);
                cout << "现在名称为：" << Current->Data.GetName() << endl;
                break;
            }
            case 2:
            {
                int atk;
                do {
                    cout << "请输入新攻击力："; cin >> atk;
                } while (InputChecking(atk));

                Current->Data.SetAtk(atk);
                cout << "现在攻击力为：" << Current->Data.GetAtk() << endl;
                break;
            }
            case 3:
            {
                int def;
                do {
                    cout << "请输入新防御力："; cin >> def;
                } while (InputChecking(def));

                Current->Data.SetDef(def);
                cout << "现在防御力为：" << Current->Data.GetDef() << endl;
                break;
            }
            default:
                cout << "请重新输入" << endl;
                break;
            }
        }
        else {
            Current = Current->Next;
            if (!Current) {
                cout << "不存在该角色，退出至主界面\n" << endl;
                return;
            }
        }

        int q;
        cout << endl << "是否退出？\n1. 是\t2. 否："; cin >> q;
        if (q == 1)
            return;
        cout << endl;
    }
}

template <typename T>
int CharacterList<T>::DetectExist(struct Node <Character>* n) {
    if (!n->Next) {
        cout << "没有任何角色。\n";
        cout << endl;
        return 1;
    }
    else return 0;
}


//数字链表
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
    cout << "不存在该数字，退回至主界面\n" << endl;
    return;
}

template <typename T>
void NumList<T>::Modify(int modinum, struct Node <int>* n) {
    struct Node<T>* Current = n->Next;
    while (Current) {
        if (Current->Data == modinum) {
            cout << "请输入新数字：";
            int NewNum; cin >> NewNum;
            Current->Data = NewNum;
            return;
        }
        Current = Current->Next;
    }
    cout << "不存在该数字，退回至主界面\n" << endl;
    return;
}

template <typename T>
int NumList<T>::DetectExist(struct Node <int>* n) {
    if (!n->Next) {
        cout << "没有任何角色。\n";
        cout << endl;
        return 1;
    }
    else return 0;
}