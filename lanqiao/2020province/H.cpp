/**
 * Created by DearDeer on 2021/04/10
 */
#include<bits/stdc++.h>
using namespace std;

#define DEER 1
#define endl '\n'
typedef long long ll;
unordered_map<string, int> vals;

int cnt(string& s) {
    if(vals.count(s)) return vals[s];
    int a[26] = {};
    int val = 0;
    for(char c : s) a[c - 'a'] = 1;
    for(int e : a) val += e;
    return vals[s] = val;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef DEER
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    
    string s;
    cin >> s;
    const int n = s.size();
    ll sum = 0;
    
    // cout << n << endl;
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j <= n; ++j) {
            string t = s.substr(i, j - i);
            cout << t << endl;
            sum += cnt(t);
        }
    }

    cout << sum << endl;

    
    return 0;
}