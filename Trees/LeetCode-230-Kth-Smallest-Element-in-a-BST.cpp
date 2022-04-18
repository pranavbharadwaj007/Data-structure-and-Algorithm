

// Iterative

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> st; 
        int cnt=0;
        TreeNode* curr=root;
        while(true){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                if(st.empty()==true)break;
                curr =st.top();
                st.pop();
                cnt++;
                if(cnt==k){
                    return curr->val;
                }
                curr=curr->right;
            }
            
        }
        return -1;
    }
};

// recursive

class Solution {
public:
    int count = 0;
    int res = -1;
    void helper( TreeNode* root, int k){
        if( root != NULL){
            if( res != -1) return;
            helper( root->left,k);
            count++;
            if( count == k){
                res = root->val;
                return;
            }
            
            helper(root->right,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        
        helper(root,k);
        return res;
    }
};
