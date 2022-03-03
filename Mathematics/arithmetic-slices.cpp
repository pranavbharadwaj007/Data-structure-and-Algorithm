class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
     int curr = 0, sum = 0;
    for (int i = 2; i < A.size(); i++) {
        if ((long)A[i] - A[i - 1] == (long)A[i - 1] - A[i - 2]) {
            curr += 1;
            sum += curr;
        }
        else curr = 0;
    }
    return sum;
    }
};
