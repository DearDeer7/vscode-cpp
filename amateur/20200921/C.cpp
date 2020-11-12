class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(K+1, vector<vector<double>>(N, vector<double>(N, 0)));
        dp[0][r][c] = 1;
        for (int k = 1; k <= K; ++k) {
            for(int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for(int d = 0; d < 8; ++d) {
                        int tr = i + dr[d];
                        int tc = j + dc[d];
                        if(tr < 0 || tr >= N || tc < 0 || tc >= N)
                            continue;
                        dp[k][i][j] += dp[k - 1][tr][tc];
                    }
                }
            }
        }

        double total = 0.0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                total += dp[K][i][j];
            }
        }
        return total / pow(8, K);
    }
private:
    vector<int> dr{1, 1, 2, 2, -1, -1, -2, -2};
    vector<int> dc{2, -2, 1, -1, 2, -2, 1, -1};
};