/**
 * Created by DearDeer on 2021/04/13/18:58
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

bool isOk(int n) {
    while(n) {
        if(n % 10 == 2 || n % 10 == 4) return false;
        n /= 10;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int n = 2019;
    int cnt = 0;
    for(int i = 1; i < 2019; ++i) {
        if(!isOk(i)) continue;
        for(int j = i + 1; j < 2019; ++j) {
            if(!isOk(j)) continue;
            for(int k = j + 1; k < 2019; ++k) {
                if(!isOk(k)) continue;
                if(i + j + k == n) {
                    cnt++;
                    // cout << i << "+" << j << "+" << k << "=" << n << endl;
                }
            }
        }
    }
    cout << cnt << endl; // 40785
    return 0;
}