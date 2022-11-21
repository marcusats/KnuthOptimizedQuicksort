#include <cstdlib>
#include <time.h>
#include <iostream>

using namespace std;


int Partition(int a[], int low, int high){
    int pivot = a[high];
    int lIndex = low;

    for (int i = low; i < high; i++){
        if(a[i]<pivot){
           int temp = a[i];
           a[i] = a[lIndex];
           a[lIndex] = temp;
           lIndex++;
        }
    }
    int temp = a[high];
    a[high] = a[lIndex];
    a[lIndex] = temp;
    
    return lIndex;
}

int Partition_r(int a[], int low, int high)
{

    srand(0);
    int random = low + rand() % (high - low);
  
    
    int temp = a[random];
    a[random] = a[high];
    a[high] = temp;
  
  
    return Partition(a, low, high);
}




void Quicksort(int a[], int low, int high ) {
    if (low < high) {
        int pivotLoc = Partition_r(a, low, high);
        Quicksort(a, low, pivotLoc - 1);
        Quicksort(a, pivotLoc + 1, high);
    }
}

void Display (int a[], int n) {
    int i =0;
    while (i<n) {
        cout<<"arr["<< i << "]" << ": " << a[i] << " "<< endl;
        i++;
    }
    cout<< endl;
}




int main() {

    int arr[] = {10, 7, 8, 9, 1, 5};
    int size = sizeof(arr)/ sizeof(int);
    
    Display(arr, size);
    Quicksort(arr, 0, size - 1);
    Display(arr, size);
    

    return 0;

}