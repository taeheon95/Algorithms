#include<iostream>
#include<vector>

using namespace std;

template<typename T>
int BinarySearch(vector<T> arr, T target, int high, int low)
{
    int mid = (high + low)/2;
    if(low > high)
        return -1;

    if(arr[mid] == target){
        return mid;
    }
    else if(arr[mid] > target){
        return BinarySearch(arr, target, high, mid+1);
    }
    else if(arr[mid] < target){
        return BinarySearch(arr, target, mid-1, low);
    }
}