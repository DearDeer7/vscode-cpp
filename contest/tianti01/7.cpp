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
    
    int n;
    string s;
    cin >> n;
    getchar();
    getline(cin, s);
    s.push_back('E');
    int sz = s.size();
    cout << sz << " ";
    int col = ceil(sz * 1.0 / n);
    char ans[n][col];
    
    int idx = 0;
    for(int i = n; i >= 0; --i) {
        for(int j = col; j >= 0; --j) {
            ans[i][j] = s[idx++];
        }
    }

    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= col; ++j) {
            if(ans[i][j] == 'E') return 0;
            cout << ans[i][j];
        }
        cout << endl;
    }

    
    return 0;
}