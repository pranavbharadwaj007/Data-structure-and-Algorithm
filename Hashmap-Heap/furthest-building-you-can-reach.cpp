
// Link : https://leetcode.com/problems/furthest-building-you-can-reach/

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue <int, vector<int>, greater<int>> pq;
        int n=heights.size();
        int br=0;
        for(int i=1;i<n;i++){
            int diff=heights[i]-heights[i-1];
            if(diff>0){
                pq.push(diff);
                if(pq.size()>ladders){
                    int top=pq.top();
                    pq.pop();
                    br+=top;
                    if(br>bricks)return i-1;
                }
            }
        }
        return n-1;
    }
