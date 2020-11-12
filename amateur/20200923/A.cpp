class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        
        vector<int> dirs{0, 1, 0, -1, 0};
        function<void(int, int)> dfs = [&](int i, int j) {
            for (int k = 0; k < 4; ++k)
            {
                int y = i + dirs[k];
                int x = j + dirs[k + 1];
                if(y < 0 || y >= m || x < 0 || x >= n || grid[y][x] == '0')
                    continue;
                grid[y][x] = '0';
                dfs(y, x);
            }
        };
        
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};