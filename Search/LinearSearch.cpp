#include<iostream>
#include<vector>

using namespace std;

template<typename T>
int LinearSearch(vector<T> arr, T target)
{
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == target)
            return i;
    }
    return -1;
}