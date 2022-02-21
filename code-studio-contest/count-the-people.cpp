
// Link : https://www.codingninjas.com/codestudio/contests/codestudio-weekend-contest-10/problems/16711?leftPanelTab=0

int count(int N, string s)
{
	int x1=0,x2=0,y1=0,y2=0;
    set<pair<int,int>>st;
    st.insert({0,0});
    for(int i=0;i<N;i++){
        if(i%2==0){
            if(s[i]=='U')x1--;
            else if(s[i]=='D')x1++;
            else if(s[i]=='L')y1--;
            else y1++;
            st.insert({x1,y1});
        }else{
            if(s[i]=='U')x2--;
            else if(s[i]=='D')x2++;
            else if(s[i]=='L')y2--;
            else y2++;
            st.insert({x2,y2});
        }
      
    }
    return st.size();
}
