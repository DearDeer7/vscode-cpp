/**
 * https://leetcode.com/problems/combination-sum/
 * author: DearDeer
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());

        vector<int> cur;

        function<void(int,int)> dfs = [&] (int target, int s) {
            if(target == 0) {
                ans.push_back(cur);
                return;
            }

            for(int i = s; i < candidates.size(); ++i) {
                if(target < candidates[i]) break; // 剪枝 canditate一旦大于target即放弃向下找
                cur.push_back(candidates[i]);
                dfs(target - candidates[i], i + 1);
                cur.pop_back();
            }
        };

        dfs(target, 0);
        return ans;
    }
};