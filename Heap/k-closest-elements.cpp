#include <bits/stdc++.h>
using namespace std;

void printKclosestElements(int arr[], int n, int k, int x) {

    priority_queue<pair<int, int>> pq;

    for(int i=0; i<k; i++) {
        pq.push({abs(arr[i]-x), i});
    }
    for(int i=k; i<n; i++) {
        int diff = abs(arr[i]-x);
        if(diff <= pq.top().first) {
            pq.pop();
            pq.push({diff, i});
        }
    }
    while (!pq.empty()) {
        cout << arr[pq.top().second] << " ";
        pq.pop();
    }
    cout << "\n";
}

int main() {

    int arr[] = {7, 1, 5, 2, 6, 7, 3, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int val = 6;

    printKclosestElements(arr, n, k, val);

    return 0;
}