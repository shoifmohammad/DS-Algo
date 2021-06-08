#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void maxHeapify(int arr[], int i, int n) {
    
    if(i>=n)
        return;
    
    int largest = i, l = 2*i+1, r = 2*i+2;
    if(l<n && arr[l] > arr[largest])
        largest = l;
    if(r<n && arr[r] > arr[largest])
        largest = r;
    
    if(largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, largest, n);
    }
}

void buildHeap(int arr[], int n) {
    
    for(int i=(n-2)/2; i>=0; i--) {
        maxHeapify(arr, i, n);
    }
}

void heapSort(int arr[], int n) {
    
    buildHeap(arr, n);
    
    int pos = n-1;
    while(pos>0) {
        swap(arr[0], arr[pos]);
        maxHeapify(arr, 0, pos);
        pos--;
    }
}

int main() {

    int arr[] = {2, 1, 4, 1, 6, 3, 8};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);
    printArray(arr, n);

    return 0;
}