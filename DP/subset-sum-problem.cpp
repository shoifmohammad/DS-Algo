#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {

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
        if(dp[i][sum])
            return true;
    }

    return dp[n][sum];
}

int main() {

    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 9;

    if(isSubsetSum(arr, n, sum))
        cout << "Subset present\n";
    else
        cout << "No such subset\n";

    return 0;
}