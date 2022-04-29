
// Link : https://leetcode.com/problems/is-graph-bipartite/

// BFS

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        for(int i=0;i<n;i++){
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

// DFS 

class Solution {
public:
    bool isValid(vector<vector<int>>& graph,vector<int>&color,int c,int node){
        if(color[node]!=0){
            return color[node]==c;
        }
        color[node]=c;
        for(auto it:graph[node]){
           if(!isValid(graph,color,-c,it))
            return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,0);
        for(int i=0;i<graph.size();i++){
            if(color[i]==0 && !isValid(graph,color,1,i)){
                return false;
            }
        }
        return true;
    }
};

// 0 ->not col
// 1-> red
// -1 -> blue
