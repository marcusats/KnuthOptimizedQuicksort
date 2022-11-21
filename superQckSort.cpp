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


void Quicksort(int a[], int low, int high ) {
    if (low < high) {
        int pivotLoc = Partition(a, low, high);
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

    int arr[] = {102, 382, 352,238, 237,1};
    int size = sizeof(arr)/ sizeof(int);
    
    Display(arr, size);
    Quicksort(arr, 0, size);
    Display(arr, size);
    

    return 0;

}