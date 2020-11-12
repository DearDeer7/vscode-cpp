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
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int ans = INT_MIN;
        maxPathSum(root, ans);
        return ans;
    }

    int maxPathSum(TreeNode* root, int& ans) {
        if(!root) return 0;
        int l = maxPathSum(root->left, ans);
        int r = maxPathSum(root->right, ans);

        int sum = root->val + l + r;
        ans = max(ans, sum);

        return max(l, r) + root->val;
    }
};