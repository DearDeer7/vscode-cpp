/**
 * Created by DearDeer on 2021/04/13/18:48
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll a, b, c;
    a = b = c = 1L;
    for(int i = 4; i <= 20190324; ++i) {
        ll t = a % 10000 + b % 10000 + c % 10000;
        a = b;
        b = c;
        c = t % 10000;
    }
    cout << c << endl; // 4659
    
    return 0;
}