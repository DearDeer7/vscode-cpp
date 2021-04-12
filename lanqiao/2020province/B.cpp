/**
 * Created by DearDeer on 2021/04/09
 */
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define DEER 1
#define endl '\n'
typedef long long ll;

int gcd(int a, int b) {
    return b > 0 ? gcd(b, a % b) : a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEER
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int cnt = 0;

    for(int i = 1; i <= 2020; ++i) {
        for(int j = 1; j <= 2020; ++j) {
            if(gcd(i, j) == 1) cnt++;
        }
    }
    cout << cnt << endl; // 1/ 1
    return 0;
}