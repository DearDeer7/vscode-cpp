class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        const int mod = 1000000007;
        vector<int> dirs{0, 1, 0, -1, 0};
        for (int n = 1; n <= N; ++n) {
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    for (int k = 0; k < 4; ++k) {
                        int y = i + dirs[k];
                        int x = j + dirs[k + 1];
                        if(y < 0 || y >= m || x < 0 || x >= n)
                            dp[n][i][j] += 1;
                        else 
                            dp[n][i][j] = (dp[n][i][j] + dp[n - 1][y][x]) % mod;
                    }
                }
            }
        }
        return dp[N][i][j];
    }
};