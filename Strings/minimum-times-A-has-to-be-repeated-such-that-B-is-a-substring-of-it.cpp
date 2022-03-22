// Link :

class Solution {
  public:
    int minRepeats(string a, string b) {
       int n=a.length();
       int m=b.length();
    string s=a;
    int cnt=1;
       while(s.length()<b.length()){
           s+=a;
           cnt++;
       }
     if(s.find(b)!=-1)return cnt;
     s+=a;
     cnt++;
     if(s.find(b)!=-1)return cnt;
      return -1;
    }
};
