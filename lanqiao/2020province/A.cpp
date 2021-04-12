/**
 * Created by DearDeer on 2021/04/09
 */
#include<bits/stdc++.h>
using namespace std;

// #define DEER 1
#define endl '\n'
typedef long long ll;

int cnt2(int n) {
    int ret = 0;
    while(n) {
        if(n % 10 == 2) ret++;
        n /= 10;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEER
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    int ans = 0;
    for(int i = 1; i <= 2020; ++i) ans += cnt2(i);
    cout << ans << endl;
    // 624
    
    return 0;
}