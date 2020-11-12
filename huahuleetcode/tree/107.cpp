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
// Solution 1 BFS + Reverse
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            ans.push_back({});
            int sz = q.size();
            while(sz--){
                auto cur = q.front(); q.pop();
                ans.back().push_back(cur->val);
                if(cur->left) {
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Solution 2 DFS
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        function<void(TreeNode*,int depth)> dfs = [&](TreeNode* root, int depth) {
            if(!root) return;
            while(ans.size() <= depth) ans.push_back({});

            ans[depth].push_back(root->val);
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        };
        dfs(root, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};