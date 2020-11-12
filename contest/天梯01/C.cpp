/**
 * Created by DearDeer on 2020/10/26
 */
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef long long ll;

const int MAXN = 501;

struct node{
    int length, cost;
};

node grid[MAXN][MAXN];
node ans;
int n,m,s,d;

int min_cost = INT_MAX;
void dfs(int y, int x, int length, int cost) {
    if(y == d || x == d) {
        if(cost < min_cost) {
            min_cost = cost;
            ans.length = length;
            ans.cost = cost;
        }
        return ;
    }

    vector<int> dirs{0,1, 0, -1, 0};
    for(int i = 0; i < 4; i++) {
        int ty = y + dirs[i];
        int tx = x + dirs[i + 1];
        if(ty < 0 || ty >= MAXN || tx < 0 || tx >= MAXN || grid[ty][tx].length == -1) continue;
        dfs(ty, tx, length + grid[ty][tx].length, cost + grid[ty][tx].cost);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 0; i < MAXN; ++i) {
        for(int j = 0; j < MAXN; ++j) grid[i][j].length = -1;
    }
    for(int i = 0; i < MAXN; ++i) grid[i][i].length = 0, grid[i][i].cost = 0;

    cin >> n >> m >> s >> d;
    for(int i = 0; i < m; ++i) {
        int a, b, l, mon;
        cin >> a >> b >> l >> mon;
        grid[a][b].length = l;
        grid[a][b].cost = mon;
    }

    dfs(s, s, 0, 0);

    cout << ans.length << " " << ans.cost << endl;

    return 0;
}