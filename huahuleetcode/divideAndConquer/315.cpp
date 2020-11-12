// unsolved
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return {};
        vector<int> ans(sz,0);


        for(int i = sz - 2; i >= 0; --i) {
            ans[i] = findSmaller(nums, tar, i + 1);
        }

        return ans;
    }

    int findSmaller(vector<int>& nums, int tar, int j) {
        int cnt = 0;
        while(j < nums.size()) {
            if(nums[j] < tar) {
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};