/**
 * https://leetcode.com/problems/permutations/
 * author:deardeer
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur; 
        int sz = nums.size();
        vector<int> used(sz, 0);
        function<void(int)> dfs = [&] (int d) {
            if(d == sz) {
                ans.push_back(cur);
                return;
            }
            for(int i = 0; i < sz; i++) {
                if(used[i]) continue;
                used[i] = 1;
                cur.push_back(nums[i]);
                dfs(d + 1);
                used[i] = 0;
                cur.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};