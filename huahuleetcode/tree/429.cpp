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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};

        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        int depth = 0;
        while(q.size()) {
            int sz = q.size();
            ans.push_back({});
            while(sz--) {
                auto curr = q.front(); q.pop();
                ans[depth].push_back(curr->val);
                for(auto child : curr->children) {
                    q.push(child);
                }
            }
            depth++;
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        function<void(Node*,int depth)> dfs = [&](Node* root, int depth) {
            if(!root) return;
            while(ans.size() <= depth) ans.push_back({});
            ans[depth].push_back(root->val);
            for(auto child : root->children) {
                dfs(child, depth + 1);
            }
        };
        dfs(root, 0);
        return ans;
    }
};