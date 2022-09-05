
// Link : https://leetcode.com/problems/n-ary-tree-level-order-traversal/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
     if (root == nullptr) return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while (!q.empty()) {
            ans.push_back({});
            for (int i = q.size(); i >= 1; i--) {
                Node* curr = q.front(); q.pop();
                ans.back().push_back(curr->val);
                for (Node* child : curr->children) {
                    q.push(child);
                }
            }
        }
        return ans;   
    }
};
