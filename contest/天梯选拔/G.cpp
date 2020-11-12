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
    
    int k,n;
    cin >> k >> n;
    vector<int> v;
    for(int i = 0; i < n; ++i) {
        int d;
        cin >>d;
        v.push_back(d);
    }

    int ans = v.back() - v.front();
    
    for(int i = 0; i < n - 1; i++) {
        int d = k - (v[i + 1] - v[i]);
        ans = min(ans, d);
    }

    cout << ans << endl;
    
    return 0;
}