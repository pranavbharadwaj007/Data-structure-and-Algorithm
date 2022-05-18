class Solution {
public:
    int strStr(string haystack, string needle) {
        int i =0, j = 0;
        int n =  haystack.size();
        int m = needle.size();
        while(i<=n-m)
        {
            j=0;
            while(haystack[i+j] ==needle[j] and j<m)
            {
                j++;
            }
            if(j == m)
                return i;
            i++;
        }
        return -1;
            
    }
};
