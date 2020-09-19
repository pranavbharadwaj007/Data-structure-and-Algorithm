#include <iostream>
#include<vector>
using namespace std;
int subarr(vector<int> &v,int n){
    int res=v[0];
    int maxend=v[0];
    for(int i=1;i<n;i++){
        maxend=max(maxend+v[i],v[i]);
        res=max(res,maxend);
    }
    return res;
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,res;
	    cin>>n;
	    vector<int>v;
	    for(int i=0;i<n;i++){
	        int p;
	        cin>>p;
	        v.push_back(p);
	    }
	    res=subarr(v,n);
	    cout<<res<<endl;
	}
	return 0;
}