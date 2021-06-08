#include <bits/stdc++.h>
using namespace std;

string largeSum(string str1, string str2) {

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    
    int n1 = str1.length(), n2 = str2.length(), i=0, j=0;
    string str = "";
    int carry = 0;
    while(i<n1 && j<n2) {
        int sum = (str1[i]-'0')+(str2[j]-'0')+carry;
        str += to_string(sum%10);
        carry = sum/10;
        i++; j++;
    }
    while(i<n1) {
        int sum = (str1[i]-'0')+carry;
        str += to_string(sum%10);
        carry = sum/10;
        i++;
    }
    while(j<n2) {
        int sum = (str2[j]-'0')+carry;
        str += to_string(sum%10);
        carry = sum/10;
        j++;
    }
    
    if(carry)
        str += '1';
    
    reverse(str.begin(), str.end());
    
    return str;
}

string minimumSum(int arr[], int n) {

    sort(arr, arr+n);
        
    string str1 = "", str2 = "";
    for(int i=0; i<n; i++) {
        if(arr[i]) {
            if(i%2 == 0)
                str1 += to_string(arr[i]);
            else
                str2 += to_string(arr[i]);
        }
    }
    
    return largeSum(str1, str2);
}

int main() {

    int arr[] = {6, 8, 4, 5, 3, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << minimumSum(arr, n) << "\n";

    return 0;
}