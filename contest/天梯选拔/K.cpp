/**
 * Created by DearDeer on 2020/10/23
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

bool isPalindrome(string& s) {
    int i = 0, j = s.size() - 1;
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++, j--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;

    if(isPalindrome(s)) {
        cout << 0 << endl;
        return 0;
    }

    // int  cnt = 0;
    
    cout << 3 << endl;
    cout << "L " << 2 << endl;
    cout << "R " << 2 << endl;
    cout << "R " << 2 * s.size() - 1 << endl;
    
    return 0;
}