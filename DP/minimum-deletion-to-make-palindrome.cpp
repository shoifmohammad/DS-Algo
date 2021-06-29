#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2) {

    int n1 = s1.length(), n2 = s2.length();
    int dp[n1+1][n2+1];

    for(int i=0; i<=n1; i++) {
        for(int j=0; j<=n2; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n1][n2];
}

int minimumDeletion(string str) {

    string s = str;
    reverse(s.begin(), s.end());

    int lps = lcs(str, s);
    return str.length() - lps;
}

int main() {

    string str = "agbcbaf";

    cout << minimumDeletion(str) << "\n";

    return 0;
}