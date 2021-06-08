#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void sortKsorted(int arr[], int n, int k) {

    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(int i=0; i<=k; i++)
        pq.push(arr[i]);
    int idx = 0;
    for(int i=k+1; i<n; i++) {
        arr[idx++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty()) {
        arr[idx++] = pq.top();
        pq.pop();
    }
}

int main() {

    int arr[] = {2, 4, 1, 5, 100, 7, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    sortKsorted(arr, n, k);
    printArray(arr, n);

    return 0;
}