#include<bits/stdc++.h>
using namespace std;

int minimumCost(int arr[], int n) {

    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+n);

    int rel = 0;
    while(pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        int total = first+second;
        rel += total;
        pq.push(total);
    }

    return rel;
}

int main() {

    int arr[] = {4, 2, 5, 3, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << minimumCost(arr, n) << "\n";

    return 0;
}