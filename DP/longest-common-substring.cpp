#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string s1, string s2) {

    int n1 = s1.length(), n2 = s2.length(), mx = 0;
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
                dp[i][j] = 0;
            
            mx = max(dp[i][j], mx);
        }
    }

    return mx;
}

int main() {

    string s1 = "abcdghs";
    string s2 = "acdghr";

    cout << longestCommonSubstring(s1, s2) << "\n";

    return 0;
}