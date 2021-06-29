/*
    Question Link: https://leetcode.com/problems/target-sum/
*/

#include <bits/stdc++.h>
using namespace std;

int targetSumWays(int arr[], int n, int target) {

    int sum = 0, count = 0;
    for(int i=0; i<n; i++)  {
        if(arr[i])
            sum += arr[i];
        else
            count++;
    }
    
    if(sum%2 != target%2)
        return 0;
    
    int s = (sum+target)/2;
    int dp[n+1][s+1];
    for(int i=0; i<=s; i++)
        dp[0][i] = 0;
    for(int i=0; i<=n; i++)
        dp[i][0] = 1;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=s; j++) {
            dp[i][j] = dp[i-1][j];
            if(arr[i-1] <= j && arr[i-1])
                dp[i][j] += dp[i-1][j-arr[i-1]];
        }
    }

    return dp[n][s]*pow(2, count);
}

int main() {

    int arr[] = {1, 1, 1, 0, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 3;

    cout << targetSumWays(arr, n, target) << "\n";
    
    return 0;
}