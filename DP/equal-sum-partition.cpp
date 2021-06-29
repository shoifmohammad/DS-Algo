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

bool equalSum(int arr[], int n) {

    double s = 0;
    for(int i=0; i<n; i++)
        s += (double)arr[i]/2;

    int sum = s;
    if(s-sum > 0)
        return false;

    return isSubsetSum(arr, n, sum);
}

int main() {

    int arr[] = {1, 12, 6, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    if(equalSum(arr, n))
        cout << "Partition possible\n";
    else
        cout << "Partition not possible\n";

    return 0;
}