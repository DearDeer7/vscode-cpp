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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> freqs;
        int max_freq = -1;
        function<int(TreeNode*)> treeSum = [&] (TreeNode* root) {
            if(!root) return 0;
            int sum = root->val + treeSum(root->left) + treeSum(root->right);
            int f = ++freqs[sum];
            max_freq = max(f, max_freq);
            return sum;
        };
        treeSum(root);
        vector<int> ans;
        for(auto it = freqs.begin(); it != freqs.end(); ++it) {
            if(it->second == max_freq) ans.push_back(it->first);
        }
        return ans;
    }
};