
// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            auto nod=it.first;
            int x=it.second.first;
            int y=it.second.second;
            mp[x][y].insert(nod->val);
            if(nod->left)q.push({nod->left,{x-1,y+1}});
            if(nod->right)q.push({nod->right,{x+1,y+1}});
        }
        vector<vector<int>>res;
        for(auto it:mp){
            vector<int>col;
            for(auto pt:it.second){
                col.insert(col.end(),pt.second.begin(),pt.second.end());
            }
            res.push_back(col);
        }
        return res;
    }
};
