#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int i, int j) {

    while(i<j) {
        if(str[i] != str[j])
            return false;
        i++;
        j--;
    }

    return true;
}

int recursion(string str, vector<vector<int>>& dp, int i, int j) {

    if(i>=j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    if(isPalindrome(str, i, j))
        return dp[i][j] = 0;

    dp[i][j] = INT_MAX;
    for(int k=i; k<j; k++) {
        dp[i][j] = min(dp[i][j], 1+recursion(str, dp, i, k)+recursion(str, dp, k+1, j));
    }

    return dp[i][j];
}

int palindromePartitioning(string str) {

    int n = str.length();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    return recursion(str, dp, 0, n-1);
}

int main() {

    string str = "abaccc";

    cout << palindromePartitioning(str) << "\n";

    return 0;
}