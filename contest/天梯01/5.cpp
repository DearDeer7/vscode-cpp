/**
 * Created by DearDeer on 2020/10/26
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<string> strs;
    string str;
    while(cin >> str) {
        strs.push_back(str);
    }
    if(!strs.size()) {
        return 0;
    }
    reverse(strs.begin(), strs.end());

    int sz = strs.size();
    // for(auto i : strs) {
    //     cout << i << ' ';
    // }
    for(int i = 0; i < sz - 1; ++i) {
        cout << strs[i] << " ";
    }
    cout << strs.back();
    
    return 0;
}