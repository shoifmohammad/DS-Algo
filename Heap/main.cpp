#include <bits/stdc++.h>
#include "heap.h"
using namespace std;

void showMinHeap(MinHeap q) {
    MinHeap h(q);
    while (!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }
    cout << "\n";
}

void showMaxHeap(MaxHeap q) {
    MaxHeap h(q);
    while (!h.empty()) {
        cout << h.top() << " ";
        h.pop();
    }
    cout << "\n";
}

int main() {

    int arr[] = {2, 5, 3, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    MaxHeap mxhp(arr, n);
    MinHeap mnhp(arr, n);

    showMaxHeap(mxhp);
    cout << mxhp.top() << " ";
    mxhp.pop();
    cout << mxhp.top() << "\n";
    showMaxHeap(mxhp);

    showMinHeap(mnhp);
    cout << mnhp.top() << " ";
    mnhp.pop();
    cout << mnhp.top() << "\n";
    mnhp.pop();
    showMinHeap(mnhp);

    return 0;
}