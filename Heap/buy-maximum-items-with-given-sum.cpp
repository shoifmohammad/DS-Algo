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

void pop(int arr[], int size) {

    swap(arr[0], arr[size-1]);
    minHeapify(arr, size-1, 0);
}

int maxItems(int arr[], int n, int sum) {
    
    buildHeap(arr, n);
    
    int count = 0;
    for(int i=0; i<n; i++) {
        if(arr[0] > sum)
            return count;
        count++;
        sum -= arr[0];
        pop(arr, n-i);
    }

    return count;
}

int main() {

    int arr[] = {3, 6, 1, 4, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 11;

    cout << maxItems(arr, n, sum) << "\n";

    return 0;
}