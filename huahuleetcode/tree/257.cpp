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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return {};
        vector<string> ans;
        vector<int> curr;

        function<void(TreeNode*)> dfs = [&] (TreeNode* root) {
            if(!root) return;
            if(!root->left && !root->right) {
                string ts;
                for(int i : curr) {
                    ts = ts + to_string(i) + "->";
                }
                ts = ts + to_string(root->val);
                ans.push_back(ts);
                return;
            }

            curr.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
            curr.pop_back();
        };
        
        dfs(root);
        
        return ans;
    }
};