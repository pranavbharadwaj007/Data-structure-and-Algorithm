
// Link : https://leetcode.com/problems/possible-bipartition/

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        vector<vector<int>>graph(n+1);
        for(int i=0;i<dis.size();i++){
            graph[dis[i][0]].push_back(dis[i][1]);
            graph[dis[i][1]].push_back(dis[i][0]);
        }
        vector<int>color(n+1,0);
        for(int i=1;i<=n;i++){
            if(color[i]==0){
                queue<int>q;
                q.push(i);
                color[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int it:graph[node]){
                        if(color[it]==color[node])return false;
                        else if(color[it]==0){
                            q.push(it);
                            color[it]=-color[node];
                        }
                    }
                }
            }
        }
        return true;
    }
};
