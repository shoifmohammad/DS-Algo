#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string str) {

    vector<int> count(26, 0);
    for(char ch: str) {
        count[ch-'a']++;
    }
    
    int mx = 0;
    char ch;
    for(int i=0; i<26; i++) {
        if(count[i] > mx) {
            mx = count[i];
            ch = 'a'+i;
        }
    }
    
    int n = str.length(), idx = 0;
    if(mx > (n+1)/2)
        return "-1";
    
    while(mx) {
        str[idx] = ch;
        idx += 2;
        mx--;
    }
    count[ch-'a'] = 0;
    for(int i=0; i<26; i++) {
        while(count[i]) {
            if(idx >= n)
                idx = 1;
            str[idx] = 'a'+i;
            idx += 2;
            count[i]--;
        }
    }
    
    return str;
}

int main() {

    string str = "kolkatacity";

    string rel = reorganizeString(str);
    if(rel == "-1")
        cout << "Not Possible";
    else
        cout << rel;
    cout << "\n";

    return 0;
}