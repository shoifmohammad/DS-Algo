#include <bits/stdc++.h>
using namespace std;

//  unbounded knapsack idea. space and time complexity O(m*n);
//  n is target to make with coins and m is size of coins array.

int minCoins(int coins[], int n, int sum) {

    int dp[n+1][sum+1];
    for(int i=0; i<=sum; i++)
        dp[0][i] = INT_MAX;
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if(coins[i-1] <= j && dp[i][j-coins[i-1]] != INT_MAX)
                dp[i][j] = min(dp[i][j], 1+dp[i][j-coins[i-1]]);
        }
    }

    return dp[n][sum] == INT_MAX ? -1 : dp[n][sum];
}

//  space optimization to O(n);

int minimumCoins(int coins[], int n, int sum) {

    int dp[sum+1];
    for(int i=0; i<=sum; i++)
        dp[i] = INT_MAX;
    dp[0] = 0;

    for(int i=0; i<n; i++) {
        for(int j=coins[i]; j<=sum; j++) {
            if(dp[j-coins[i]] != INT_MAX)
                dp[j] = min(dp[j], 1+dp[j-coins[i]]);
        }
    }

    return dp[sum] == INT_MAX ? -1 : dp[sum];
}

int main() {

    int coins[] = {2, 1, 5};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 11;

    cout << minimumCoins(coins, n, sum) << "\n";

    return 0;
}
