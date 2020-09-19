#include <iostream>
using namespace std;
int normalMax(int arr[],int n){
 int res=arr[0],max_end=arr[0];
 for(int i=1;i<n;i++){
     max_end=max(arr[i],max_end+arr[i]);
     res=max(res,max_end);
 }
 return res;
    
}
int overallMax(int arr[],int n){
    int max_n=normalMax(arr,n);
    if(max_n<0){
        return max_n;
    }
    int arr_sum=0;
    for(int i=0;i<n;i++){
        arr_sum+=arr[i];
        arr[i]=-arr[i];
        
    }
    int max_c=arr_sum+normalMax(arr,n);
    return max(max_n,max_c);
}
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,res;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    res=overallMax(arr,n);
	    cout<<res<<endl;
	}
	return 0;
}