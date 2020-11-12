// Author: DearDeer
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MAX 0x3f3f3f3f
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    while(cin >> a >> b) {
        int az = a.size(), bz = b.size();
        vector<vector<int>> dp(bz+1, vector<int>(az+1, 0));
        for (int i = 0; i <= az; ++i) dp[0][i] = 1;
        for(int i = 1; i <= bz; ++i) {
            for(int j = 1; j <= az; ++j) {
                if(b[i-1] == a[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                }
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        // for(auto i : dp) {
        //     for (int d : i) cout << d << ' ';
        //     cout << '\n';
        // }
        cout << dp[bz][az] << '\n';
    }
    return 0;
}
