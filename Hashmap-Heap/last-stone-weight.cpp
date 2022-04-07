
// Link : https://leetcode.com/problems/last-stone-weight/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto it:stones){
            pq.push(it);
        }
        while(pq.size()){
            if(pq.size()==1)return pq.top();
            if(pq.size()>=2){
                int y=pq.top();
                pq.pop();
                int x=pq.top();
                pq.pop();
                if(x!=y){
                    pq.push(y-x);
                }
            }
        }
        return 0;
    }
};
