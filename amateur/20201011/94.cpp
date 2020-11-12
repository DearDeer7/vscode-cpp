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
// solution 2 iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> vals;
        
        return vals;
    }
};

// solution 1 recursive 
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(!root) return {};
//         vector<int> vals;

//         function<void(TreeNode*)> helper = [&] (TreeNode* root) {
//             if(!root) return;
//             helper(root->left);
//             vals.push_back(root->val);
//             helper(root->right);
//         };
//         helper(root);
//         return vals;
//     }
// };