#include<iostream>
#include"ArrayList.h"

using namespace std;

template<class Type>
ArrayList<Type>::ArrayList()
{
    numofData = 0;
    curPosition = -1;
}

template<class Type>
void ArrayList<Type>::LInsert(Type data)
{
    if(numofData>=100)
    {
        puts("Can't Save.");
        return;
    }
    arr[numofData++] = data;
}

template<class Type>
bool ArrayList<Type>::LFirst(Type *pdata)
{
    if(numofData == 0)
        return false;
    curPosition = 0;
    pdata = &arr[0];
    return true;
}

template<class Type>
bool ArrayList<Type>::LNext(Type *pdata)
{
    if(curPosition >= numofData -1)
        return false;
    curPosition++;
    *pdata = arr[curPosition];
    return true;
}

template<class Type>
Type ArrayList<Type>::LRemove()
{
    int rpos = curPosition;
    int num = numofData;
    Type rdata = arr[rpos];
    for(int i=rpos; i<num-1; i++)
        arr[i] = arr[i+1];
    curPosition--;
    numofData--;
    return rdata;
}

template<class Type>
int ArrayList<Type>::LCount()
{
    return numofData;
}