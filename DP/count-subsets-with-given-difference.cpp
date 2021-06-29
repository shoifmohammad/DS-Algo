#include <bits/stdc++.h>
using namespace std;

int countSubsets(int arr[], int n, int sum) {

    int dp[n+1][sum+1];
    for(int i=0; i<=sum; i++)
        dp[0][i] = 0;
    for(int i=0; i<=n; i++)
        dp[i][0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if(arr[i-1] <= j)
                dp[i][j] += dp[i-1][j-arr[i-1]];
        }
    }

    return dp[n][sum];
}

int subsetsWithGivenDifference(int arr[], int n, int diff) {

    int sum = 0;
    for(int i=0; i<n; i++)
        sum += arr[i];
    
    if(sum%2 != diff%2)
        return 0;

    int target = (sum+diff)/2;

    return countSubsets(arr, n, target);
}

int main() {

    int arr[] = {1, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int diff = 1;

    cout << subsetsWithGivenDifference(arr, n, diff) << "\n";

    return 0;
}