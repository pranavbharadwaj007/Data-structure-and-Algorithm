
// Link : https://leetcode.com/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<string> garyString = generate(n);
        vector<int> ans;
        for(auto i:garyString)
        {
            ans.push_back(stoi(i,0,2));
        }
        return ans;
    }
    
    vector<string> generate(int n)
    {
        if(n==1)
        {
           vector<string> an;
            an.push_back("0");
            an.push_back("1");
            return an;
        }
        vector<string> ans;
        vector<string> temp = generate(n-1);
        for(int i=0;i<temp.size();i++)
        {
            ans.push_back("0"+temp[i]);
        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            ans.push_back("1"+temp[i]);
        }
        return ans;
    }
    
};
