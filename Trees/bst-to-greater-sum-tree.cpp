
// Link : https://practice.geeksforgeeks.org/problems/bst-to-greater-sum-tree/1#

class Solution
{
    public:
    int prev=0;
    void transformTree(struct Node *root)
    {
        if(root==NULL)return;
        transformTree(root->right);
        int s=root->data+prev;
        root->data=prev;
        prev=s;
        transformTree(root->left);
        
    }
};
