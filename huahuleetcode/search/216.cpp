/**
 * https://leetcode.com/problems/combination-sum-iii/
 * author: deardeer
 */
// Approach 1 DFS + Backtracking [preferred]
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans; 
        vector<int> cur;

        function<void(int, int, int)> dfs = [&] (int s, int k, int n) {
            if(k == 0) {
                if(n == 0) ans.push_back(cur);
                return;
            }

            for(int i = s; i <= 9; ++i) {
                if(i > n) break;
                cur.push_back(i);
                dfs(i + 1, k - 1, n - i);
                cur.pop_back();
            }
        };

        dfs(1, k, n);
        return ans;
    }
};

// Approach 2 Bit Manipulation
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        for(int i = 0; i <= (1 << 9); ++i) {
            vector<int> cur;
            int sum = 0;
            for(int j = 1; j <= 9; ++j) {
                if((i >> j - 1) & 1) {
                    cur.push_back(j);
                    sum += j;
                }
            }
            if(sum == n && cur.size() == k) ans.push_back(cur);
        }

        return ans;
    }
};