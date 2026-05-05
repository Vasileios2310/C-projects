#include <stdbool.h>
#include <stdio.h>

void swap(int* a , int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[] , int low , int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        //find the first element grater than the pivot
        while (arr[i] <= pivot && i <= high - 1){
            i++;
        }

        //find the first element smaller than the pivot
        while (arr[j] >= pivot && j >= low + 1){
            j--;
        }
        if(i<j){
            swap(&arr[i] , &arr[j]);
        }
    }
    swap(&arr[low] , &arr[j]);
    return j;
}

void quickSort(int arr[] , int low , int high){
    if (low < high){
        int pivot = partition(arr , low , high);

        quickSort(arr , low , pivot - 1);
        quickSort(arr , pivot + 1 , high);
    }
}

void printArray(int arr[] , int size){
    int i;
    for(i = 0; i < size; i++){
        printf("%d  ", arr[i]);
    }
}

int main(){
    int arr[] = { 4, 2, 5, 3, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // calling quickSort() to sort the given array
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}