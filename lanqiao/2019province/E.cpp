/**
 * Created by DearDeer on 2021/04/13/19:13
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

struct node{
    int y, x;
    // string path;
    // node(int _y, int _x, string _s): y(_y), x(_x) , path(_s) {}
    // node(int _y, int _x, string& _s):y(_y), x(_x) , path(_s) {}
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int m = 4, n = 6;
    int sx, sy, tx, ty;
    sx = sy = 0, ty = m - 1, tx = n - 1;

    vector<int> dy{1,0,0,-1},
                dx{0,-1,1,0};
    vector<char> chs{'D', 'L', 'R', 'U'};

    vector<vector<int>> maze(m, vector<int>(n)), vis(m, vector<int>(n, 0));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) 
            cin >> maze[i][j];
    }
    

    vector<string> ans;
    auto bfs = [&] () {
        queue<node> q;
        q.push({sy, sx});
        while(q.size()) {
            int sz = q.size();
            while(sz--) {
                node t = q.front(); q.pop();
                int y = t.y, x = t.x;
                // string s = t.path;
                vis[y][x] = 0;
                if(y == ty && x == tx) {
                    cout << y << x << endl;
                    // cout << s << endl;
                    return 0;
                }
                for(int i = 0; i < 4; ++i) {
                    y += dy[i];
                    x += dx[i];
                    // s += chs[i];
                    if(y < 0 || y >= m || x < 0 || x >= n || maze[y][x] || vis[y][x]) 
                        continue;
                    vis[y][x] = 1;
                    q.push({y, x});
                }
            }
        }
        cout << "-1" << endl;
    };

    bfs();

    
    return 0;
}