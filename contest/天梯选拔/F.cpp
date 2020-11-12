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
    
    int x;
    cin >> x;
    int ans = 0;
    for(int i = 5; i >= 1; i--) {
        if(x >= i) {
            ans += x / i;
            x %= i;
        }
            // cout << x << endl;
    }
    
    cout << ans << endl;
    return 0;
}