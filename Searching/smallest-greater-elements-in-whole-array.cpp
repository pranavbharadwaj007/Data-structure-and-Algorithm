
// Link : https://practice.geeksforgeeks.org/problems/smallest-greater-elements-in-whole-array2751/1#

int* greaterElement(int arr[], int n)
{

    int *ans = new int[n];
    vector<int> res;
    for(int i = 0; i < n; i++)
    {
        res.push_back(arr[i]);
    }
    sort(res.begin(),res.end());
    for(int i=0;i<n;i++){
        auto tem=upper_bound (res.begin(), res.end(), arr[i])-res.begin();
        if(tem==n){
        ans[i]=(-10000000);
        }else{
            ans[i]=res[tem];
        }
    }
    return ans;
}
