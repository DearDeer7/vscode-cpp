/**
 * Created by DearDeer on 2020/11/25
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> v{1,2,3,1,2,3};
    vector<bool> used(v.size(), 0);
    int n = v.size();

    vector<int> cur;
    int cnt = 0;
    function<void(int)> dfs = [&](int d) {
        if(d == n) {
            for(int d : cur) cout << d << ' ';
            cout << endl;
            cnt++;
            return;
        }

        for(int i = 0; i < n; ++i) {
            if(used[i]) continue;
            used[i] = true;
            cur.push_back(v[i]);
            dfs(d + 1);
            cur.pop_back();
            used[i] = false;
        }
    };

    dfs(0);
    cout << cnt << endl;
    
    return 0;
}