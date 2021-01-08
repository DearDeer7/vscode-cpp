/**
 * https://leetcode.com/problems/delete-node-in-a-bst/
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
//     TreeNode* deleteNode(TreeNode* root, int key) {
//         if(!root) return nullptr;
//         if(key < root->val) {
//             root->left = deleteNode(root->left, key);
//         }
//         else if(key > root->val) {
//             root->right = deleteNode(root->right, key);
//         }
//         else {
//             if(root->left && root->right) {
//                 TreeNode *min = root->right;
//                 while(min->left) min = min->left;
//                 root->val = min->val;
//                 root->right = deleteNode(root->right, min->val);
//             }            
//             else {
//                 TreeNode *new_root = root->left == nullptr ? root->right : root->left;
//                 // root->left = root->right = nullptr;
//                 delete root;
//                 return new_root;
//             }
//         }
//         return root;
//     }
// };

// solution 2 operate nodes
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            TreeNode* new_root = nullptr;
            if(root->left == nullptr) {
                new_root = root->right;
            }
            else if(root->right == nullptr) {
                new_root = root->left;
            }
            else {
                TreeNode* parent = root;
                new_root = root->right;
                while(new_root->left) {
                    parent = new_root;
                    new_root = new_root->left;
                }

                if(parent != root) {
                    parent->left = new_root->right;
                    new_root->right = root->right;
                }
                new_root->left = root->left;    
            }
            delete root;
            return new_root;
        }
        return root;
    }
};