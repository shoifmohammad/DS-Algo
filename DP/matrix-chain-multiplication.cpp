#include <bits/stdc++.h>
using namespace std;

int recursion(int arr[], vector<vector<int>>& dp, int i, int j) {

    if(i>=j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];

    dp[i][j] = INT_MAX;
    int rel;
    for(int k=i; k<j; k++) {
        rel = arr[i-1]*arr[k]*arr[j]+recursion(arr, dp, i, k)+recursion(arr, dp, k+1, j);
        dp[i][j] = min(dp[i][j], rel);
    }

    return dp[i][j];
}

int mcm(int arr[], int n) {

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return recursion(arr, dp, 1, n-1);
}

int main() {

    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << mcm(arr, n) << "\n";

    return 0;
}