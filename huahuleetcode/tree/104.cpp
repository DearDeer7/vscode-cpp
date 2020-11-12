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
// Solution 1 Iterative
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(!root) return 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         int depth = 0;
//         while(q.size()) {
//             int sz = q.size();
//             while(sz--) {
//                 TreeNode* curr = q.front(); q.pop();
//                 if(!curr) continue;
//                 q.push(curr->left);
//                 q.push(curr->right);
//             }
//             depth++;
//         }
//         return depth - 1;
//     }
// };

// Solution 2 Recursive
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return max(l, r) + 1;
    }
};