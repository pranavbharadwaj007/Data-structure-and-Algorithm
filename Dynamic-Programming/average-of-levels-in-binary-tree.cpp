
// Link : https://leetcode.com/problems/average-of-levels-in-binary-tree/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
        queue<TreeNode*>q;
        if(root==NULL)return ans;
        q.push(root);
        int cnt=0;
     
        while(q.size()>0){
            int sz=q.size();
            int tem=sz;
            double res=0;

            while(sz--){
            auto it=q.front();
            q.pop();
                res+=(it->val);
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
        
            res=res/tem;
            ans.push_back(res);
        }
        return ans;
    }
};
