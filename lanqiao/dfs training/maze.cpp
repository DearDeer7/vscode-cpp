/**
 * Created by DearDeer on 2021/04/12/15:10
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }
    int sy, sx, ty, tx;
    cin >> sy >> sx >> ty >> tx;
    cout << sy << sx << ty << tx << endl;
    vector<int> dirs{0,1,0,-1,0};
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int cnt = 100;
    function<int(int, int, int)> dfs = [&] (int sy, int sx, int d) {
        if(cnt-- == 0) exit(0);
        for(int i = 0; i < 8; ++i) {
            int y = sy + dirs[i];
            int x = sx + dirs[i + 1];
            if(y < 0 || y >= m || x < 0 || x >= n || vis[y][x] || mat[y][x]) continue;
            cout << y << "," << x << endl;
            if(sy == ty && sx == tx) {
                return d;
            }
            vis[y][x] = 1;
            dfs(y, x, d + 1);
            vis[y][x] = 0;
        }
        return -1;
    };

    cout << dfs(sy, sx, 0) << endl;
    
    return 0;
}