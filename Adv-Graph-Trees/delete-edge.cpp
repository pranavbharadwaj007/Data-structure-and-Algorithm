const int m=1e9+7;
void dfs(int vertex,int par,vector<int> g[],vector<int>&sub_tree,vector<int> &val){
    sub_tree[vertex]+=val[vertex-1];
    for(int child:g[vertex]){
        if(child==par)continue;
        dfs(child,vertex,g,sub_tree,val);
        sub_tree[vertex]+=sub_tree[child];
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    vector<int> g[A.size()+1];
    vector<int> sub_tree(A.size()+1,0);
    for(auto &it:B){
        g[it[0]].push_back(it[1]);
        g[it[1]].push_back(it[0]);

    }
    dfs(1,0,g,sub_tree,A);
    long long ans=0;
    for(int i=2;i<=A.size();i++){
        int part1=sub_tree[i];
        int part2=sub_tree[1]-part1;
        ans=max(ans,(part1*1LL*part2)%m);
    }
    return ans;
}
