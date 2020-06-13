#include<iostream>
#include"ArrayList.h"

using namespace std;

template<class LData>
ArrayList<LData>::ArrayList()
{
    numofData = 0;
    curPosition = -1;
}

template<class LData>
void ArrayList<LData>::LInsert(LData data)
{
    if(numofData>=100)
    {
        puts("Can't Save.");
        return;
    }
    arr[numofData++] = data;
}

template<class LData>
bool ArrayList<LData>::LFirst(LData *pdata)
{
    if(numofData == 0)
        return false;
    curPosition = 0;
    pdata = &arr[0];
    return true;
}

template<class LData>
bool ArrayList<LData>::LNext(LData *pdata)
{
    if(curPosition >= numofData -1)
        return false;
    curPosition++;
    *pdata = arr[curPosition];
    return true;
}

template<class LData>
LData ArrayList<LData>::LRemove()
{
    int rpos = curPosition;
    int num = numofData;
    LData rdata = arr[rpos];
    for(int i=rpos; i<num-1; i++)
        arr[i] = arr[i+1];
    curPosition--;
    numofData--;
    return rdata;
}

template<class LData>
int ArrayList<LData>::LCount()
{
    return numofData;
}