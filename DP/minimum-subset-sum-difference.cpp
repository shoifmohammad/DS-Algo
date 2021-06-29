#include <bits/stdc++.h>
using namespace std;

int minimumDifference(int arr[], int n) {

    int s = 0;
    for(int i=0; i<n; i++)
        s += arr[i];
    
    int sum = s/2;
    bool dp[n+1][sum+1];
    for(int i=0; i<=sum; i++)
        dp[0][i] = false;
    for(int i=0; i<=n; i++)
        dp[i][0] = true;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if(arr[i-1] <= j)
                dp[i][j] |= dp[i-1][j-arr[i-1]];
        }
    }

    for(int i=sum; i>0; i--) {
        if(dp[n][i])
            return s-2*i;
    }
    return s;
}

int main() {

    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << minimumDifference(arr, n) << "\n";

    return 0;
}