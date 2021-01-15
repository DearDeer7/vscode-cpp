/**
 * Created by DearDeer on 2021/01/14
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s = "vile";
    string cur;
    vector<bool> used(s.size(), false);

    function<void()> dfs = [&] () { 
        if(cur.size() == s.size()) {
            cout << cur << endl;
            return;
        }

        for(int i = 0; i < s.size(); ++i) {
            if(used[i]) continue;
            used[i] = true;
            cur.push_back(s[i]);
            dfs();
            cur.pop_back();
            used[i] = false;
        }
    };

    dfs();
    
    return 0;
}