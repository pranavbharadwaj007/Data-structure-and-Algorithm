
// Link : https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int _k, vector<int>& nums) {
        k=_k;
        for(auto it:nums){
            pq.push(it);
            if(pq.size()>k)pq.pop();
            
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k)pq.pop();
        return pq.top();
    }
};
