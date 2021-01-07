/**
 * https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

    TreeNode* buildBST(vector<int>& nums, int l, int r) {
        if(l > r) return nullptr;
        int m = l + (r - l) / 2;
        auto root = new TreeNode(nums[m]);
        root->left = buildBST(nums, l, m - 1);
        root->right = buildBST(nums, m + 1, r);
        return root;
    }
};