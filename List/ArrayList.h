#ifndef __ArrayList_h__
#define __ArrayList_h__

#include<iostream>
using namespace std;
template<class Type>
class ArrayList
{
private:
    Type* arr[100];
    int numofData;
    int curPosition;
public:
    ArrayList();
    void LInsert(Type data);

    bool LFirst(Type *pdata);
    bool LNext(Type *pdata);

    Type LRemove();
    int LCount();
};

#endif