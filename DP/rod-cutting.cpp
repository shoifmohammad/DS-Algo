#include <bits/stdc++.h>
using namespace std;

//  Normal dp idea.

int cutRod(int prices[], int n) {

    int dp[n];
    dp[0] = 0;

    for(int i=1; i<=n; i++) {
        dp[i] = prices[i-1];
        for(int j=1; j<=i/2; j++)
            dp[i] = max(dp[i], dp[j]+dp[i-j]);
    }

    return dp[n];
}

//  unbounded knapsack idea.

int cutRod_II(int prices[], int n) {

    int dp[n+1][n+1];
    
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i-1][j];
            if(i <= j)
                dp[i][j] = max(dp[i][j], prices[i-1]+dp[i][j-i]);
        }
    }

    return dp[n][n];
}

int main() {

    int prices[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(prices)/sizeof(prices[0]);

    cout << cutRod(prices, n) << "\n";

    return 0;
}