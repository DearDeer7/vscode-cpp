class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }

    int findMin(vector<int>& nums, int l, int r) {
        // 1 or 2 elements
        if(l + 1 >= r) return min(nums[l], nums[r]);

        // sorted
        if(nums[l] < nums[r]) return nums[l];
        int mid = l + (r - l) / 2;
        return min(
            findMin(nums, l, mid),
            findMin(nums, mid + 1, r)
        );
    }
};