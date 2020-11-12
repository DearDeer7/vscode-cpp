/**
 * Created by DearDeer on 2020/10/13/21:52
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
// O(nlogn)
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
//         if(!root) return true;
//         int l = h(root->left), r = h(root->right);
//         if(abs(l - r) > 1) return false;
//         return isBalanced(root->left) && isBalanced(root->right);
//     }

//     int h(TreeNode* root) {
//         if(!root) return 0;
//         return max(h(root->left), h(root->right)) + 1;
//     }
// };

// O(n)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool balanced = true;
        h(root, balanced);
        return balanced;
    }

    int h(TreeNode* root, bool& balanced) {
        if(!root) return 0;
        int l = h(root->left), r = h(root->right);
        if(abs(l-r) > 1) {
            balanced = false;
            return -1;
        }
        return max(l, r) + 1;
    }
};