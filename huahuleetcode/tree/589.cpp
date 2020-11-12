/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// Solution 1 Recursive
// class Solution {
// public:
//     vector<int> preorder(Node* root) {
//         if(!root) return {};
//         vector<int> vals;
//         preorder(root, vals);
//         return vals;
//     }

//     void preorder(Node* root, vector<int>& vals) {
//         if(!root) return;
//         vals.push_back(root->val);
//         for(auto child : root->children) {
//             preorder(child, vals);
//         }
//     }
// };

// Solution 2 Iterative
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root) return {};
        vector<int> vals;
        stack<Node*> st;
        st.push(root);
        while(st.size()) {
            Node* curr = st.top(); st.pop();
            vals.push_back(curr->val);
            for(auto it = curr->children.rbegin(); it != curr->children.rend(); ++it) {
                st.push(*it);
            }
        }
        return vals;
    }
};