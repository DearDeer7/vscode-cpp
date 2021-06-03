/**
 * Created by DearDeer on 2021/04/14/19:42
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
    const int n = s.size();
    ll sum = 0;
    for(int i = n - 1; i >= 0; --i) {
        int d = -1;
        if(isdigit(s[i])) d = s[i] - '0';
        else d = s[i] - 'A' + 10;
        // cout << d << " ";
        sum += d * pow(16, n - i - 1);  
    }
    // cout << endl;
    cout << sum << endl;
    
    return 0;
}