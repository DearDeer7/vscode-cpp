/**
 * Created by DearDeer on 2021/04/13/21:18
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;
bool isOk(int x) {
    while(x) {
        int t = x % 10;
        if(t == 2 || t == 0 || t == 1 || t == 9) return true;
        x /= 10;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    ll sum = 0;
    for(int i = 1; i <= n; ++i) {
        if(isOk(i)) {
            // cout << i << endl;
            sum += i;
        }
    }
    cout << sum << endl;
    
    return 0;
}