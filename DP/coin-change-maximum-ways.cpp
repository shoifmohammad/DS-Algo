#include <bits/stdc++.h>
using namespace std;

//  unbounded knapsack idea. space and time complexity O(m*n);
//  n is target to make with coins and m is size of coins array.

int maximumCoins(int coins[], int n, int sum) {

    int dp[n+1][sum+1];
    for(int i=0; i<=sum; i++)
        dp[0][i] = 0;
    for(int i=0; i<=n; i++)
        dp[i][0] = 1;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            dp[i][j] = dp[i-1][j];
            if(coins[i-1] <= j)
                dp[i][j] += dp[i][j-coins[i-1]];
        }
    }

    return dp[n][sum];
}

// space optimization to O(n);

int maximumWays(int coins[], int n, int sum) {

    int dp[sum+1];
    for(int i=0; i<=sum; i++)
        dp[i] = 0;
    dp[0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=coins[i]; j<=sum; j++) {
            dp[j] += dp[j-coins[i]];
        }
    }

    return dp[sum];
}

int main() {

    int coins[] = {2, 5, 3, 6};
    int n = sizeof(coins)/sizeof(coins[0]);
    int sum = 10;

    cout << maximumWays(coins, n, sum) << "\n";

    return 0;
}