// Link : https://leetcode.com/problems/binary-search-tree-iterator/

class BSTIterator {
private:
    stack<TreeNode*>st;
    void pushAll(TreeNode* node){
       for(;node!=NULL;st.push(node),node=node->left){  
              }
        }
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
