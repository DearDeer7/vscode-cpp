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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!t) return true;
        if(!s) return false;
        if(isSameTree(s, t)) return true;
        return isSubTree(s->left, t) || isSubTree(s->right, t);    
    }
    bool isSameTree(TreeNode* s, TreeNode* t) {
        // if(!s || !t) return (s == nullptr) && (t == nullptr);
        if(!s && !t) return true;
        if(!s || !t) return false;
        return (s->val == t->val) 
            && isSameTree(s->left, t->left) 
            && isSameTree(s->right, t->right);
    }
};