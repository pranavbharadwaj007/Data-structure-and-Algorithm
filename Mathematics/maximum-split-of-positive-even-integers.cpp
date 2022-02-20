// Link : https://leetcode.com/problems/maximum-split-of-positive-even-integers/

class Solution {
public:
    vector<long long> maximumEvenSplit(long long fs) {
        if(fs&1)return {};
        long long vem=70;
        long long tt=fs;
        long long prev=0;
        int n=100;
        vector<long long> ans;
        if(fs==2)return {2};
        for(long long i=2;i<fs;i+=2){
            
            if(tt){
                if(tt<i){
                    ans.pop_back();
                    ans.push_back(prev+tt);
                    cout<<prev<<" "<<tt;
                    break;
                }else{
                tt=tt-i;
                ans.push_back(i); 
                }
            
            }
            else{
                cout<<"break";
                break;
            }
            prev=i;
        }
        if(tt){
            ans.pop_back();
            ans.push_back(tt+prev);
        }
        return ans;
    }
};
