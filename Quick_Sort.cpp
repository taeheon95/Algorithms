#include<iostream>

void quickSort(int [], int, int);
int partition(int [], int, int);

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low -1);

    for(int j = low; j<high; j++){
        if(arr[j]<=pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i+1);
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}