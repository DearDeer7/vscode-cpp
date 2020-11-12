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

// Solution 1 BFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()) {
            int sz = q.size();
            ans.push_back({});
            while(sz--) {
                auto curr = q.front(); q.pop();
                ans.back().push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        return ans;
    }
};

// Solution 2 DFS
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        function<void(TreeNode*,int)> dfs = [&](TreeNode* root, int depth) {
            if(!root) return;
            while(ans.size() <= depth) ans.push_back({});
            ans[depth].push_back(root->val);
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        };
        dfs(root, 0);
        return ans;
    }
};