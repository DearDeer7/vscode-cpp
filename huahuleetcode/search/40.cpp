/**
 * https://leetcode.com/problems/combination-sum-ii/
 * author: deardeer
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> cur;

        function<void(int, int)> dfs = [&] (int target, int s) {
            if(target == 0) {
                ans.push_back(cur);
                return;
            }

            for(int i = s; i < candidates.size(); ++i) {
                if(candidates[i] > target) break;
                if(i > s && candidates[i] == candidates[i - 1]) continue;
                cur.push_back(candidates[i]);
                dfs(target - candidates[i], i + 1);
                cur.pop_back();
            }
        };
        dfs(target, 0);

        return ans;
    }

};