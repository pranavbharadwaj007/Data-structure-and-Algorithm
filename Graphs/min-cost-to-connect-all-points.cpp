
// Link : https://leetcode.com/problems/min-cost-to-connect-all-points/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
      for(int i=0;i<n;i++){
          int x1=points[i][0];
          int y1=points[i][1];
          for(int j=i+1;j<n;j++){
              int x2=points[j][0];
              int y2=points[j][1];
              int dist=abs(x1-x2)+abs(y1-y2);
              adj[i].push_back({dist,j});
              adj[j].push_back({dist,i});
              
          }
      }
        int res=0;
        set<int>st;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mt;
        mt.push(make_pair(0,0));
        while(st.size()<n){
            auto it=mt.top();
            mt.pop();
            if(st.find(it.second)!=st.end()){
                continue;
            }
            res+=(it.first);
            st.insert(it.second);
            for(auto pt:adj[it.second]){
                if(st.find(pt.second)==st.end()){
                    mt.push({pt.first,pt.second});
                }
            }
        }
        return res;
    }
};
