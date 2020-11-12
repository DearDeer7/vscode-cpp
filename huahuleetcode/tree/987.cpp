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

// Solution url: https://www.youtube.com/watch?v=5xL_N2S3-QU
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        int max_x = INT_MIN;
        int min_x = INT_MAX;
        map<pair<int,int>, set<int>> bag;
        traverse(root, min_x, max_x, bag, 0, 0);
        vector<vector<int>> ans(max_x - min_x + 1);
        for(auto& i : bag) {
            int index = i.first.second - min_x;
            ans[index].insert(ans[index].end(), i.second.begin(), i.second.end());
        }
        return ans;
    }

    void traverse(TreeNode* root, int& min_x, int& max_x, 
        map<pair<int,int>, set<int>>& bag, 
        int y, int x) {
        if(!root) return;
        min_x = min(x, min_x);
        max_x = max(x, max_x);
        bag[{y,x}].insert(root->val);
        traverse(root->left, min_x, max_x, bag, y+1, x-1);
        traverse(root->right, min_x, max_x, bag, y+1, x+1);
    } 
};


