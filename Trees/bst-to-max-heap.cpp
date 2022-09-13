
// https://practice.geeksforgeeks.org/problems/bst-to-max-heap/1

class Solution{
  public:
  void inorder(Node* root,vector<int>&vec){
      if(root==NULL)return;
      inorder(root->left,vec);
      vec.push_back(root->data);
      inorder(root->right,vec);
  }
  void postorder(Node* root,vector<int>&vec,int &i){
      if(root==NULL)return;
      postorder(root->left,vec,i);
      postorder(root->right,vec,i);
      root->data=vec[i++];
  }
    void convertToMaxHeapUtil(Node* root)
    {
      vector<int>vec;
      int i=0;
      inorder(root,vec);
      postorder(root,vec,i);
    }    
};
