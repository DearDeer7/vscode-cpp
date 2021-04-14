/**
 * Created by DearDeer on 2021/04/13/21:29
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int n;
    cin >> n;
    int d = log(n) / log(2) + 1;
    // cout << d << endl;
    vector<ll> sums;
    for(int i = 0; i < d; i++) {
        ll sum = 0;
        for(int j = 1; j <= (1 << i); ++j ) {
            int v; 
            cin >> v;
            sum += v;
        }
        sums.push_back(sum);
    }

    ll msum = INT_MIN, idx = -1;
    for(int i = 0; i < d; ++i) {
        if(sums[i] > msum) {
            msum = sums[i];
            idx = i + 1;
        }
    }

    cout << idx << endl;
    
    return 0;
}