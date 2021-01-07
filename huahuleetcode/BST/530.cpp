/**
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
//     int getMinimumDifference(TreeNode* root) {
//         inOrder(root);
//         int min_diff = vals[1] - vals[0];
//         for(int i = 2; i < vals.size(); ++i) {
//             int d = vals[i] - vals[i - 1];
//             min_diff = min(min_diff, d);
//         }
//         return min_diff;

//     }
// private:
//     vector<int> vals;
//     void inOrder(TreeNode* root) {
//         if(!root) return;
//         inOrder(root->left);
//         vals.push_back(root->val);
//         inOrder(root->right);
//     }
// };
// O(1) space
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        min_diff = INT_MAX;
        prev = nullptr;
        inOrder(root);
        return min_diff;
    }
private:
    int min_diff;
    int *prev;
    void inOrder(TreeNode* root) {
        if(!root) return;
        inOrder(root->left);
        if(prev) min_diff = min(min_diff, root->val - *prev);
        prev = &root->val;
        inOrder(root->right);
    }
};