#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {

    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

inline int left(int i) {
    return 2*i+1;
}

inline int right(int i) {
    return 2*i+2;
}

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void maxHeapify(int arr[], int n, int i) {

    if(i>=n)
        return;

    int largest = i, l = left(i), r = right(i);
    if(l<n && arr[l] > arr[largest])
        largest = l;
    if(r<n && arr[r] > arr[largest])
        largest = r;
    if(largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void minToMaxHeap(int arr[], int n) {

    for(int i=(n-2)/2; i>=0; i--) {
        maxHeapify(arr, n, i);
    }
}

int main() {

    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    minToMaxHeap(arr, n);
    printArray(arr, n);

    return 0;
}