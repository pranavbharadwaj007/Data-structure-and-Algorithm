class Solution {
public:
    pair<int,pair<int,int>> longestZigZag_(TreeNode* root){
        pair<int,pair<int,int>>ans={-1,{-1,0}};
        if(root==NULL)return ans;
        
        pair<int,pair<int,int>> left=longestZigZag_(root->left);
        pair<int,pair<int,int>> right=longestZigZag_(root->right);
        ans.second.second=max(max(left.second.second,right.second.second),max(left.second.first,right.first)+1);
        ans.first=left.second.first+1;
        ans.second.first=right.first+1;
        return ans;
    }
    int longestZigZag(TreeNode* root) {
    
        pair<int,pair<int,int>>ans=longestZigZag_(root);
        return ans.second.second;
    }
};
