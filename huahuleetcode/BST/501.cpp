/**
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/
 * author:deardeer
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
    vector<int> findMode(TreeNode* root) {
        int _val = 0;
        int cnt = 0;
        int max_cnt = 0;
        vector<int> ans;

        auto visit = [&] (int val) {
            if(cnt > 0 && val == _val) {
                cnt++;
            }
            else {
                cnt = 1;
                _val = val;
            }

            if(cnt > max_cnt) {
                max_cnt = cnt;
                ans.clear();
            }

            if(cnt == max_cnt) {
                ans.push_back(val);
            }
        };

        function<void(TreeNode*)> inOrder = [&] (TreeNode* root) {
            if(!root) return;
            inOrder(root->left);
            visit(root->val);
            inOrder(root->right);
        };

        inOrder(root);

        return ans;
    }
};