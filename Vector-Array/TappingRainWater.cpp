#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int trap(int v[],int n){
    int res=0;
   int lmax[n];
   int rmax[n];
    lmax[0]=v[0];
    for(int i=1;i<n;i++){
        lmax[i]=max(v[i],lmax[i-1]);
    }
    rmax[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--){
        rmax[i]=max(v[i],rmax[i+1]);
    }
    for(int i=1;i<n-1;i++){
        res=res+(min(lmax[i],rmax[i])-v[i]);
    }
    return res;
    
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,res;
	    cin>>n;
	    int v[n];
	    for(int i=0;i<n;i++){
	        int p;
	        cin>>p;
	        
	      v[i]=p;
	    }
	    res=trap(v,n);
	    cout<<res<<endl;
	}
	return 0;
}