#pragma once
#include<iostream>
using namespace std;

static int InputChecking(int m) {
    try {
        if (cin.fail())
            throw - 1;
        else
            return 0;
    }
    catch (...) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "�����������������\n" << endl;
        return 1;
    }
}