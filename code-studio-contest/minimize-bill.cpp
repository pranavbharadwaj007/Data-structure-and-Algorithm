long long totalBill(int n, vector<int>& a)
{
    long long sum=0;
    int maxi=a[0];
    for(auto it:a){
        maxi=max(maxi,it);
        sum+=it;
    }
    sum=sum-(2*maxi);
    return sum;
}
