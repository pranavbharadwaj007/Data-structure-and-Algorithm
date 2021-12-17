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
