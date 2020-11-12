// solution 1 recursive
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> vals;
        function<void(TreeNode*)> helper = [&] (TreeNode* root) {
            if(!root) return ;
            vals.push_back(root->val);
            helper(root->left);
            helper(root->right);
        };
        helper(root);
        return vals;
    }
};

// solution 2 iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> vals;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr || st.size()) {
            while(curr) {
                vals.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top()->right; st.pop();
        }
        return vals;
    }
    // // or
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if (!root) return {};
    //     vector<int> vals;
    //     stack<TreeNode*> st;
    //     st.push(root);
        
    //     while(st.size()) {
    //         TreeNode* curr = st.top(); st.pop();
    //         vals.push_back(curr->val);
    //         // !!! enstack order
    //         if(curr->right) st.push(curr->right);
    //         if(curr->left) st.push(curr->left);
    //     }
    //     return vals;
    // }
};