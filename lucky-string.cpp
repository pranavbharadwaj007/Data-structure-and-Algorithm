// https://www.codingninjas.com/codestudio/problems/lucky-string_3583485?source=youtube&campaign=Strivercontest6thfeb&utm_source=youtube&utm_medium=affiliate&utm_campaign=Strivercontest6thfeb&leftPanelTab=0
int makeLucky(string s, int n)
{
  int cnt=0;
    for(int i=1;i<s.length()-1;i++){
      if(s[i-1]==s[i] && s[i]==s[i+1]){
          cnt++;
      }
    }
    return cnt;
}
