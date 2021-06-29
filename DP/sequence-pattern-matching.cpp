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

//  Approach using help of LCS

bool isPattern(string s1, string s2) {

    return lcs(s1, s2) == s2.length();
}

//  Efficient approach.

bool doesPatterMatch(string s1, string s2) {

    int n1 = s1.length(), n2 = s2.length();
    int i=0, j=0;
    while(i<n1 && j<n2) {
        if(s1[i] == s2[j])
            j++;
        i++;
    }

    return j == n2;
}

int main() {

    string s1 = "adxcpy";
    string s2 = "axy";

    // if(isPattern(s1, s2))
    if(doesPatterMatch(s1, s2))
        cout << "Pattern Matching\n";
    else
        cout << "Pattern doesn't match\n";

    return 0;
}