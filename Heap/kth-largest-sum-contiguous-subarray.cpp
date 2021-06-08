#include <bits/stdc++.h>
using namespace std;

int KthLargestSum(int arr[], int n, int k) {

    int sum[n+1];
    sum[0] = 0;
    for(int i=0; i<n; i++)
        sum[i+1] = arr[i]+sum[i];

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            int val = sum[j]-sum[i-1];
            if(pq.size() < k) {
                pq.push(val);
            }
            else {
                if(pq.top() < val) {
                    pq.pop();
                    pq.push(val);
                }
            }
        }
    }

    return pq.top();
}

int main() {

    int arr[] = {-5, 20, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    cout << KthLargestSum(arr, n, k) << "\n";

    return 0;
}