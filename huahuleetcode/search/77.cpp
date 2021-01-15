/**
 * https://leetcode.com/problems/combinations/
 * author:deardeer
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;

        vector<int> cur;

        function<void(int,int)> dfs = [&] (int d, int s) {
            if(d == k) {
                ans.push_back(cur);
                return;
            }

            for(int i = s; i <= n; ++i) {
                cur.push_back(i);
                dfs(d + 1, i + 1);
                cur.pop_back();
            }
        };

        dfs(0, 1);

        return ans;
    }
};