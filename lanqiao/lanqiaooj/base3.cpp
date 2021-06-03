/**
 * Created by DearDeer on 2021/04/14/17:52
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
    // why is this answer wrong ?
    // string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // for(int i = 0; i < n; ++i) {
    //     for(int l = i; l > 0; --l) cout << chars[l];
    //     for(int r = 0; r < m - i; ++r) cout << chars[r];
    //     cout << endl;
    // }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << char('A' + abs(i - j));
        }
        cout << endl;
    }
    return 0;
}