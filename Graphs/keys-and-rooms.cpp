
// Link : https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        vis[0]=1;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            auto pt=q.front();
            q.pop();
            for(auto it:rooms[pt]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push(it); 
                }   
            }
        }
        for(auto it:vis){
            if(it==0)return false;
        }
        return true;
    }
};
