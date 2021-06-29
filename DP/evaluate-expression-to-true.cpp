#include <bits/stdc++.h>
using namespace std;

//  This one is top down approach.

int recursion(string str, vector<vector<vector<int>>>& dp, int i, int j, bool choice) {

    if(i>j)
        return 0;
    
    if(i == j) {
        if(choice)
            return str[i] == 'T';
        else
            return str[i] == 'F';
    }

    if(choice && dp[i][j][0] != -1)
        return dp[i][j][0];
    else if(!choice && dp[i][j][1] != -1)
        return dp[i][j][1];

    int ans = 0;
    for(int k=i+1; k<j; k+=2) {
        int leftTrue = recursion(str, dp, i, k-1, true);
        int leftFalse = recursion(str, dp, i, k-1, false);
        int rightTrue = recursion(str, dp, k+1, j, true);
        int rightFalse = recursion(str, dp, k+1, j, false);
        if(str[k] == '&') {
            if(choice) {
                ans += (leftTrue*rightTrue);
            }
            else {
                ans += (leftTrue*rightFalse + leftFalse*rightTrue + leftFalse*rightFalse);
            }
        }
        else if(str[k] == '|') {
            if(choice) {
                ans += (leftTrue*rightFalse + leftFalse*rightTrue + leftTrue*rightTrue);
            }
            else {
                ans += (leftFalse*rightFalse);
            }
        }
        else if(str[k] == '^') {
            if(choice) {
                ans += (leftTrue*rightFalse + leftFalse*rightTrue);
            }
            else {
                ans += (leftTrue*rightTrue + leftFalse*rightFalse);
            }
        }
    }

    if(choice)
        dp[i][j][0] = ans;
    else
        dp[i][j][1] = ans;

    return ans;
}

int evaluate(string str) {

    int n = str.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));

    return recursion(str, dp, 0, n-1, true);
}

//  This one is bottom up dp solution.

int bottomUpSolution(string str) {

    int n = str.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    for(int gap=0; gap<n; gap++) {

        for(int i=0, j=gap; j<n; i++, j++) {
            
            if(i==j) {
                if(str[i] == 'T')
                    dp[i][j][0] = 1;
                else
                    dp[i][j][1] = 1;
                continue;
            }

            for(int k=i+1; k<j; k += 2) {
            
                int leftTrue = (i < k) ? dp[i][k-1][0] : 0;
                int leftFalse = (i < k) ? dp[i][k-1][1] : 0;
                int rightTrue = (k < j) ? dp[k+1][j][0] : 0;
                int rightFalse = (k < j) ? dp[k+1][j][1] : 0;

                if(str[k] == '&') {
                    dp[i][j][0] += (leftTrue*rightTrue);
                    dp[i][j][1] += (leftTrue*rightFalse + leftFalse*rightTrue + leftFalse*rightFalse);
                }
                else if(str[k] == '|') {
                    dp[i][j][0] += (leftTrue*rightFalse + leftFalse*rightTrue + leftTrue*rightTrue);
                    dp[i][j][1] += (leftFalse*rightFalse);
                }
                else if(str[k] == '^') {
                    dp[i][j][0] += (leftTrue*rightFalse + leftFalse*rightTrue);
                    dp[i][j][1] += (leftTrue*rightTrue + leftFalse*rightFalse);
                }
            }
        }
    }

    return dp[0][n-1][0];
}

int main() {

    string str = "T|F&T^F";

    cout << bottomUpSolution(str) << "\n";

    return 0;
}