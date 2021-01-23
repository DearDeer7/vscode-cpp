/**
 * https://leetcode.com/problems/subsets-ii/
 * author: deardeer
 */

// Approach 1 Bit Manipulation
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        int sz = nums.size();
        for(int i = 0; i <= 1 << sz; ++i) {
            vector<int> cur;
            for(int j = 0; j < sz; ++j) {
                if((i >> j) & 1) cur.push_back(nums[j]);
            }
            ans.insert(cur);
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

// Approach 2 DFS
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> cur;

        function<void(int, int)> dfs = [&] (int s, int d) {
            if(cur.size() == d) {
                ans.push_back(cur);
                return;
            }
            for(int i = s; i < nums.size(); ++i) {
                if(i > s && nums[i] == nums[i - 1]) continue; // not break
                cur.push_back(nums[i]);
                dfs(i + 1, d);
                cur.pop_back();
            }
        };

        for(int d = 0; d <= nums.size(); ++d) {
            dfs(0, d);
        }

        return ans;
    }
};

// Approach 3 One Pass DFS
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> cur;

        int sz = nums.size();

        function<void(int)> dfs = [&] (int s) {

            ans.push_back(cur);
            if(cur.size() == sz) {
                return;
            }
            for(int i = s; i < nums.size(); ++i) {
                if(i > s && nums[i] == nums[i - 1]) continue;
                cur.push_back(nums[i]);
                dfs(i + 1);
                cur.pop_back();
            }
        };

        dfs(0);

        return ans;
    }
};