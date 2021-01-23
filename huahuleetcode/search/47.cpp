/**
 * https://leetcode.com/problems/permutations-ii/
 * author: deardeer
 */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        int sz = nums.size();
        vector<int> used(sz, 0);
        sort(nums.begin(), nums.end());
        function<void(int)> dfs = [&] (int d) {
            if(d == sz) {
                ans.push_back(cur);
                return;
            }
            for(int i = 0; i < sz; i++) {
                if(used[i]) continue;
                // Same number can be only used once at each depth.
                if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
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