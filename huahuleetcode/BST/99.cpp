/**
 * https://leetcode.com/problems/recover-binary-search-tree/\
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
class Solution {
public:
    void recoverTree(TreeNode* root) {
        first = nullptr, second = nullptr, prev = nullptr;
        inOrder(root);
        swap(first->val, second->val);
    }

private:
    TreeNode *first, *second;
    TreeNode *prev;
    void inOrder(TreeNode* root) {
        if(!root) return;
        inOrder(root->left);
        if(prev && prev->val > root->val) {
            if(!first) first = prev;
            second = root;
        }
        prev = root;
        inOrder(root->right);
    }
};