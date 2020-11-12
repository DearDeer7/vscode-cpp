class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        // if(m == 1 && n == 1) return 0; 
        vector<vector<int>> dp(m, vector(n, 0));
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;

        for (int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i == 0 && j == 0)
                    continue;
                if(obstacleGrid[i][j] == 1)
                    continue;
                if (i > 0) {
                    dp[i][j] += obstacleGrid[i - 1][j] != 1 ? dp[i - 1][j] : 0;
                }
                if(j > 0) {
                    dp[i][j] += obstacleGrid[i][j - 1] != 1 ? dp[i][j - 1] : 0;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};