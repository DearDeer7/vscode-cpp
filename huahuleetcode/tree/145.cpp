// // Author: DearDeer
// // solution 1 recursive
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         if(!root) return {};
//         vector<int> vals;

//         function<void(TreeNode*)> helper = [&] (TreeNode* root) {
//             if(!root) return;
//             helper(root->left);
//             helper(root->right);
//             vals.push_back(root->val);
//         };

//         helper(root);

//         return vals;
//     }
// };

// Author: DearDeer
// solution 2 iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        deque<int> vals;

        stack<TreeNode*> st;
        st.push(root);

        // simulate revese postorderTraversal
        while(st.size()) {
            TreeNode* curr = st.top(); st.pop();
            vals.push_front(curr->val);
            // !!! enstack order
            if(curr->left) st.push(curr->left);
            if(curr->right) st.push(curr->right);
        }

        return vector<int>(vals.begin(), vals.end());
    }
};