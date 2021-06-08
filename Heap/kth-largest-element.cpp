#include <bits/stdc++.h>
using namespace std;

inline int left(int i) {
    return (2*i+1);
}

inline int right(int i) {
    return (2*i+2);
}

void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void minHeapify(int arr[], int n, int i) {
    
    if(i>=n)
        return;
    
    int smallest = i, l = left(i), r = right(i);
    if(l<n && arr[l] < arr[smallest])
        smallest = l;
    if(r<n && arr[r] < arr[smallest])
        smallest = r;
    
    if(smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void buildHeap(int arr[], int n) {

    for(int i=(n-2)/2; i>=0; i--) {
        minHeapify(arr, n, i);
    }
}

int KthLargestElement(int arr[], int n, int k) {

    buildHeap(arr, k);
    
    for(int i=k; i<n; i++) {
        if(arr[i] > arr[0]) {
            swap(arr[0], arr[i]);
            minHeapify(arr, k, 0);
        }
    }

    return arr[0];
}

int main() {

    int arr[] = {7, 1, 5, 2, 6, 7, 3, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 6;

    cout << KthLargestElement(arr, n, k) << "\n";

    return 0;
}