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
    int sumNumbers(TreeNode* root) {

        int curr = 0, ans = 0;

        function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if(!root) return;
            if(!root->left && !root->right) {
                curr = curr * 10 + root->val;
                cout << curr << endl;
                ans += curr;
                curr = curr / 10;
                return;
            }

            curr = curr * 10 + root->val;
            dfs(root->left);
            dfs(root->right);
            curr /= 10;
        };
        dfs(root);

        return ans;
    }
};