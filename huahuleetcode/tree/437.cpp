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
// Bad Solution
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        int cnt = 0;
        vector<int> curr;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int sum) {
            if(!root) return;
            
            if(sum == root->val) {
                // for(int i : curr) cout << i << ' ';
                // cout << sum << '\n';
                cnt++;
                // return;
            }

            curr.push_back(root->val);
            dfs(root->left, sum - root->val);
            dfs(root->right, sum - root->val);
            curr.pop_back();
        };
        dfs(root, sum);
        cnt += pathSum(root->left, sum);
        cnt += pathSum(root->right, sum);
        return cnt;
    }
};
// Solution 1 Recursive
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return helper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int helper(TreeNode* root, int sum) {
        if(!root) return 0;
        sum -= root->val;
        return (sum == 0 ? 1 : 0) + helper(root->left, sum) + helper(root->right, sum);
    }
};

// Solution 2 Prefix Sum
