#include <bits/stdc++.h>
using namespace std;

string shortestSuperSequence(string s1, string s2) {

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

    string str = "";
    int i=n1, j=n2;
    while(i>0 && j>0) {
        if(s1[i-1] == s2[j-1]) {
            str += s1[i-1];
            i--;
            j--;
        }
        else {
            if(dp[i-1][j] > dp[i][j-1]) {
                str += s1[i-1];
                i--;
            }
            else {
                str += s2[j-1];
                j--;
            }
        }
    }
    while(i>0) {
        str += s1[i-1];
        i--;
    }
    while(j>0) {
        str += s2[j-1];
        j--;
    }

    reverse(str.begin(), str.end());
    return str;
}

int main() {

    string s2 = "AGGTAB";
    string s1 = "GXTXAYB";

    cout << shortestSuperSequence(s1, s2) << "\n";

    return 0;
}