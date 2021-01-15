/**
 * https://leetcode.com/problems/subsets/
 * author:deardeer
 */
// Solution 1 DFS
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans; 
//         vector<int> cur;

//         function<void(int,int)> dfs = [&] (int d, int s) {
//             if(d == 0) {
//                 ans.push_back(cur);
//                 return;
//             }
//             for(int i = s; i < nums.size(); ++i) {
//                 cur.push_back(nums[i]);
//                 dfs(d - 1, i + 1);
//                 cur.pop_back();
//             }
//         };

//         for(int i = 0; i <= nums.size(); ++i) {
//             cur.clear();
//             dfs(i, 0);
//         }

//         return ans;
//     }
// };

// Solution 2 Binary 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> cur;
        int sz = nums.size();
        for(int s = 0; s < 1 << sz; ++s) {
            cur.clear();
            for(int i = 0; i < sz; ++i) {
                if(s & (1 << i)) cur.push_back(nums[i]);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};