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
// Solution 1 DFS
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int sum) {
//         if(!root) return false;
//         if(!root->left && !root->right) return root->val == sum;
//         return dfs(root, sum);
//     }

//     bool dfs(TreeNode* root, int sum) {
//         // if(!root) return sum == 0;
//         if(!root) return false;
//         if(!root->left && !root->right) {
//             return sum == root->val;
//         }
//         return dfs(root->left, sum - root->val) 
//             || dfs(root->right, sum - root->val);
//     }
// };
//Solution 2 Recursive
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        if(!root->left && !root->right) return root->val == sum;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};