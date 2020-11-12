/**
 * Created by DearDeer on 2020/11/02
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    vector<int> coins(n);
    for(int i = 0; i < n; ++i) cin >> coins[i];
    sort(coins.begin(), coins.end());

    vector<int> curr;
    bool flag = false;
    function<void(int,int)> dfs = [&](int idx, int left) {
        if(left < 0 || flag) return ;
        if(left == 0) {
            flag = true;
            for(auto it = curr.begin(); it != curr.end() - 1; ++it) {
                cout << *it << " ";
            }
            cout << curr.back();
            return;
        }

        for(int i = idx; i < n; ++i) {
            curr.push_back(coins[i]);
            dfs(idx + 1, left - coins[i]);
            curr.pop_back();
        }
    };
    dfs(0, m);
    
    if(flag == false) {
        cout << "No Solution";
    }
    
    return 0;
}