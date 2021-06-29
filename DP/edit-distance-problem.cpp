#include <bits/stdc++.h>
using namespace std;

int editDistance(string &s1, string &s2) {

    int n1 = s1.length(), n2 = s2.length();
    int dp[n1+1][n2+1];
    for(int i=0; i<=n1; i++)
        dp[i][0] = i;
    for(int i=0; i<=n2; i++)
        dp[0][i] = i;

    for(int i=1; i<=n1; i++) {
        for(int j=1; j<=n2; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
        }
    }

    return dp[n1][n2];
}

int main() {

    string s1 = "geek";
    string s2 = "gesek";

    cout << editDistance(s1, s2) << "\n";

    return 0;
}