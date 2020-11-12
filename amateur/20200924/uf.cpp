// Accepted
// runtime:48ms
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();

        int t = m * n;
        vector<int> fa(t, 0);
        for (int i = 0; i < t; ++i)
            fa[i] = i;

        int cnt = m * n;
        function<int(int)> Find = [&](int x) {
            if (fa[x] == x)
                return x;
            else
                return fa[x] = Find(fa[x]);
        };
        auto Union = [&](int x, int y) {
            int p = Find(x), q = Find(y);
            if(p == q)
                return;
            else fa[p] = q, cnt--;
        };
        vector<int> dirs{0, 1, 0, -1, 0};
        int zeros = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    for(int k = 0; k < 4; ++k) {
                        int y = i + dirs[k];
                        int x = j + dirs[k + 1];
                        if(y < 0 || x < 0 || y >= m || x >= n || grid[y][x] == '0')
                            continue;
                        Union(y * n + x, i * n + j);
                    }
                }
                else
                    zeros++;
            }
        }
        return cnt - zeros;
    }
};