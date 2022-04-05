
// Link : https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0;
        int i=0;
        int j=height.size()-1;
        while(i<j){
            int w=j-i;
            int h=min(height[i],height[j]);
            int ns=w*h;
            res=max(res,ns);
            if(height[i]<height[j]){
                i++;
            }else{
                j--;
            }
        }
        return res;
    }
};
