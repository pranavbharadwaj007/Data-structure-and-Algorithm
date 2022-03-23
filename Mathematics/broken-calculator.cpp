// Link : https://leetcode.com/problems/broken-calculator/

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int cnt=0;
        while(1){
            if(target==startValue)return cnt;
            if(target&1)target++;
            else {
                if(target>startValue){
                    target/=2;
                }else{
                    return cnt+(startValue-target);
                }
            };
            cnt++;
        }
        return cnt;
    }
};
