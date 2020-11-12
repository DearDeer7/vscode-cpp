/**
 * Created by DearDeer on 2020/10/23
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    if(s[2] == s[3] && s[4] == s[5]) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}