#pragma once
#include<iostream>
using namespace std;
template<class LData>
class ArrayList
{
private:
    LData* arr[100];
    int numofData;
    int curPosition;
public:
    ArrayList();
    void LInsert(LData data);

    bool LFirst(LData *pdata);
    bool LNext(LData *pdata);

    LData LRemove();
    int LCount();
};

