class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left)
            {
            TreeNode* prev=curr->left;
            while(prev->right){
                prev=prev->right;
            }
            prev->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
            curr=curr->right;
        }
        
    }
};


// recursion

class Solution
{
    private:
       Node* head=NULL;Node* prev=NULL;
    void helper(Node* root){
        if(root==NULL)return;
        helper(root->left);
        if(prev==NULL)head=root;
        else{
            root->left=prev;
            prev->right=root;
            
        }
        prev=root;
        helper(root->right);
    }
    public: 
    //Function to convert binary tree to doubly linked list and return it.
 
    Node * bToDLL(Node *root)
    {
        helper(root);
        return head;
    }
};
