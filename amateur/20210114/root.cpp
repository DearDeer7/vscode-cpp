/**
 * Created by DearDeer on 2021/01/15
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

// 求最小重复子串，没有返回”“
string root(string s) {
    int slen = s.size();
    for(int i = 1; i <= s.size(); ++i) {
        string t = s.substr(i);
        int tlen = t.size();
        if(slen % tlen != 0) continue;
        bool ok = true;
        for(int i = 0; i < slen; i += tlen) {
            if(s.substr(i, tlen) != t) {
                ok = false;
                break;
            }
        }
        if(ok) {
            return t;
        }
    }
    return "";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << root("ababab") << endl;
    cout << root("aaa") << endl;
    cout << root("aba") << endl;
    
    return 0;
}