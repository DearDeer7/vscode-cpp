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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2) return (root1 == nullptr) && (root2 == nullptr);
        vector<int> ans1, ans2;
        dfs(root1, 0, ans1);
        dfs(root2, 0, ans2);
        return ans1 == ans2;
        // if(ans1.size() != ans2.size()) return false;
        // for(int i = 0; i < ans1.size(); ++i) {
        //     if(ans1[i] != ans2[i]) return false;
        // }
        // return true;
    }

    void dfs(TreeNode*root, int depth, vector<int>& ans) {
        if(!root) return;
        if(!root->left && !root->right) ans.push_back(root->val);
        dfs(root->left, depth + 1, ans);
        dfs(root->right, depth + 1, ans);
    }
};