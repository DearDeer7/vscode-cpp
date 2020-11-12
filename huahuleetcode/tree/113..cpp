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
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans; 
        vector<int> curr;
        if(!root) return {};
        if(!root->left && !root->right && sum == root->val) {
            ans.push_back({sum});
            return ans;
        }

        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int sum) {
            if(!root->left && !root->right && sum == root->val) {
                ans.push_back(curr);
                ans.back().push_back(root->val);
                return;
            }

            if(root->left) {
                curr.push_back(root->val);
                dfs(root->left, sum - root->val);
                curr.pop_back();
            }
            if(root->right) {
                curr.push_back(root->val);
                dfs(root->right, sum - root->val);
                curr.pop_back();
            }
        };
        dfs(root, sum);
        return ans;
    }
};

// Solution 2
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans; 
        vector<int> curr;

        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int sum) {
            if(!root) return;
            if(!root->left && !root->right) {
                if(root->val == sum) {
                    ans.push_back(curr);
                    ans.back().push_back();
                }
                return;
            }

            curr.push_back(root->val);
            dfs(root->left, sum - root->val);
            dfs(root->right, sum - root->val);
            curr.pop_back();
        };
        dfs(root, sum);
        return ans;
    }
};