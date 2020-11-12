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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isMirror(root, root);
    }

    bool isMirror(TreeNode* p, TreeNode* q) {
        if(!p || !q) return (q == nullptr) && (p == nullptr);
        if(p->val != q->val) return false;
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }

};