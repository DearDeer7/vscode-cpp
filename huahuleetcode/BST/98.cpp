/**
 * https://leetcode.com/problems/validate-binary-search-tree/
 * author: DearDeer
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
// Solution 1
// class Solution {
// public:
//     bool isValidBST(TreeNode* root) {
//         return isValidBST(root, nullptr, nullptr);
//     }
// private:
//     bool isValidBST(TreeNode* root, int *min_val, int *max_val) {
//         if(!root) return true;
//         if((min_val && root->val <= *min_val) || (max_val && root->val >= *max_val))
//             return false;  
//         return isValidBST(root->left, min_val, &root->val)
//             && isValidBST(root->right, &root->val, max_val);
//     }
// };
// Solution 2 inorder traversal
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        pre = nullptr;
        return InOrder(root);    
    }
private:
    TreeNode* pre;
    bool InOrder(TreeNode* root) {
        if(!root) return true;
        if(InOrder(root->left) == false) return false;
        if(pre && pre->val >= root->val) return false;
        pre = root;
        return InOrder(root->right);
    }
    
};