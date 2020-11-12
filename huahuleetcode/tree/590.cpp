/**
 * Created by DearDeer on 2020/10/12
 */
#include<bits/stdc++.h>
using namespace std;
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
// // Solution 1 Recursive
// class Solution {
// public:
//     vector<int> postorder(Node* root) {
//         if(!root) return {};
//         vector<int> vals;
//         postorder(root, vals);
//         return vals;
//     }

//     void postorder(Node* root, vector<int>& vals) {
//         if(!root) return;
//         for(auto child : root->children) {
//             postorder(child, vals);
//         }
//         vals.push_back(root->val);
//     }
// };

// Solution 2 Iterative
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root) return {};
        deque<int> vals;
        stack<Node*> st;
        st.push(root);
        while(st.size()) {
            Node* curr = st.top(); st.pop();
            vals.push_front(curr->val);
            for(auto it = curr->children.rbegin(); it !=curr->children.rend(); ++it) {
                st.push(*it);
            }
        }
        return vals;
    }
};