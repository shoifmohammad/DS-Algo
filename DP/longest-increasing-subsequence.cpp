#include <bits/stdc++.h>
using namespace std;

//  time complexity is O(n*n).

int LIS(int arr[], int n) {

    int lis[n];
    for(int i=0; i<n; i++) {
        lis[i] = 1;
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i])
                lis[i] = max(lis[i], 1+lis[j]);
        }
    }

    return lis[n-1];
}

int ceil(int arr[], int right, int x) {

    int left = 0, mid, idx;
    
    while(left <= right) {
        mid = left + (right-left)/2;
        if(arr[mid] < x)
            left = mid+1;
        else {
            idx = mid;
            right = mid-1;
        }
    }

    return idx;
}

//  optimized solution. time complexity is O(nlogn).

int lisOptimized(int arr[], int n) {

    int lis[n], pos = 0;
    lis[pos] = arr[0];

    for(int i=1; i<n; i++) {
        if(lis[pos] < arr[i]) {
            lis[++pos] = arr[i];
            continue;
        }
        else {
            lis[ceil(lis, pos, arr[i])] = arr[i];
        }
    }

    return pos+1;
}

int main() {

    int arr[] = {3, 1, 5, 3, 2, 6, 4, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << lisOptimized(arr, n) << "\n";

    return 0;
}