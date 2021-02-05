/**
 * Created by DearDeer on 2021/02/05
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tar = 20190324;

    ll a = 1, b = 1, c = 1, d;
    for(int i = 4; i <= tar; ++i) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }

    // string s = to_string(d);
    // // cout << s << endl;
    // cout << s.substr(s.size() - 4, 4) << endl;
    
    return 0;
}
