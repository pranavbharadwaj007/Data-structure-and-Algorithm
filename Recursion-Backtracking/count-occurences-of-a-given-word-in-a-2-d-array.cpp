
// Link : https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1

class Solution{
    public:
    int dfs(int i,int j,vector<vector<char> > &mat, string &target,int k,int n,int m){
        if(i>=0 && j>=0 && i<n && j<m && target[k]==mat[i][j]){
            int found=0;
            if(k==target.length()-1){
                found++;
                
            }else{
            char ch=mat[i][j];
            mat[i][j]='#';
            
            found+=dfs(i+1,j,mat,target,k+1,n, m);
            found+=dfs(i,j+1,mat,target,k+1,n, m);
            found+=dfs(i-1,j,mat,target,k+1,n, m);
            found+=dfs(i,j-1,mat,target,k+1,n, m);
            
            mat[i][j]=ch;
            }
            return found;
        }
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=dfs(i,j,mat,target,0,n, m);
            }
        }
        return ans;
    }
