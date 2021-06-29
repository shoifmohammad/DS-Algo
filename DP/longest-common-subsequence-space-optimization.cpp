#include <bits/stdc++.h>
using namespace std;

int lcs(string& s1, string& s2) {

    int n1 = s1.length(), n2 = s2.length();
    int dp[2][n2+1];

    int idx;
    for(int i=0; i<=n1; i++) {
        idx = i&1;
        for(int j=0; j<=n2; j++) {
            if(i == 0 || j == 0) {
                dp[idx][j] = 0;
                continue;
            }
            if(s1[i-1] == s2[j-1])
                dp[idx][j] = 1+dp[1-idx][j-1];
            else
                dp[idx][j] = max(dp[1-idx][j], dp[idx][j-1]);
        }
    }

    return dp[idx][n2];
}

int main() {

    string s1 = "abcdgh";
    string s2 = "aedfhr";

    cout << lcs(s1, s2) << "\n";

    return 0;
}