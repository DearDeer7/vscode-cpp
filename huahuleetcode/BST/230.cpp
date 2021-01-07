/**
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * author: DearDeer
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
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> sorted;

//         function<void(TreeNode*)> inOrder = [&] (TreeNode* root) {
//             if(!root) return;
//             inOrder(root->left);
//             sorted.push_back(root->val);
//             inOrder(root->right);
//         };

//         inOrder(root);
//         return sorted[k - 1];
//     }
// };

// O(1) space
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        int cnt = 0;
        int ans = root->val;
        function<void(TreeNode*)> inOrder = [&] (TreeNode* root) {
            if(!root) return;
            inOrder(root->left);
            if(cnt++ == k - 1) ans = root->val;
            inOrder(root->right);
        };

        inOrder(root);
        return ans;
    }
};