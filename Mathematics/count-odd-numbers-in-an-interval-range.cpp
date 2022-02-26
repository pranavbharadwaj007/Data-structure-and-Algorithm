class Solution {
public:
    int countOdds(int low, int high) {
        int num=high-low;
        num=num/2;
        if(low&1 || high&1)num++;
        return num;
    }
};
