class Solution {
public:
    int trap(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int lmax=0;
        int rmax=0;
        int res=0;
        while(l<=r){
            if(height[l]<=height[r]){
                if(lmax<height[l]){
                    lmax=height[l];
                }else{
                  res+=(lmax-height[l]);  
                }
                l++;
            }else{
               if(rmax<=height[r]){
                   rmax=height[r];
               }else{
                   res+=(rmax-height[r]);
               }
                r--;
            }
        }
        return res;
    }
};
