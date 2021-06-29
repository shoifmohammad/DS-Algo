#include <bits/stdc++.h>
using namespace std;

int longestRepeatingSubsequence(string str) {

    int n1 = str.length(), n2 = n1;
    int dp[n1+1][n2+1];

    for(int i=0; i<=n1; i++) {
        for(int j=0; j<=n2; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if(str[i-1] == str[j-1] && i != j)
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n1][n2];
}

int main() {

    string str = "aabebcdbd";

    cout << longestRepeatingSubsequence(str) << "\n";

    return 0;
}