#include <bits/stdc++.h>
using namespace std;

int maxVal(int wt[], int val[], int n, int capacity) {

    int dp[n+1][capacity+1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=capacity; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else {
                dp[i][j] = dp[i-1][j];
                if(wt[i-1] <= j) {
                    dp[i][j] = max(dp[i][j], val[i-1]+dp[i-1][j-wt[i-1]]);
                }
            }
        }
    }

    return dp[n][capacity];
}

int main() {

    int wt[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    int n = sizeof(wt)/sizeof(wt[0]);
    int capacity = 50;

    cout << maxVal(wt, val, n, capacity) << "\n";

    return 0;
}