#include <iostream>
#include <vector>

using namespace std;

template <typename T>
int BinarySearch(vector<T> arr, T target, int high, int low)
{
    int mid = (high + low) / 2;
    if (low > high)
        return -1;

    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return BinarySearch(arr, target, high, mid + 1);
    }
    else if (arr[mid] < target)
    {
        return BinarySearch(arr, target, mid - 1, low);
    }
}

int main()
{
    vector<int> test_array = {1, 4, 6, 7, 8, 10, 11};

    int index = BinarySearch(test_array, 7, test_array.size(), 0);
    cout << "target num : " << 7 << endl;
    cout << "answer index : " << index << endl;
    cout << "answer num : " << test_array[index]<<endl;
}