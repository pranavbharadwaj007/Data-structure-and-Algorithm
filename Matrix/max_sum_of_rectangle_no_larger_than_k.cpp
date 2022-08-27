


class Solution {
public:
    int find_max(vector<int>& arr, int k)
    {
        int n = arr.size();
        
        int maxi = INT_MIN;
       
        int curr_sum = 0;
        

        
        set<int> s;
        
 
        s.insert(0);
        
        for(int i = 0; i < n; i++)
        {

            
            curr_sum += arr[i];
            
    
            
            auto it = s.lower_bound(curr_sum - k);
            
      
            
            if(it != s.end())
            {
                maxi = max(maxi, curr_sum - *it);
            }
            
        
            
            s.insert(curr_sum);
        }
        
        return maxi;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        
        int m = matrix[0].size();
        
        int maxi = INT_MIN;
        
       
        
        for(int start_row = 0; start_row < n; start_row++)
        {
            vector<int> col_array(m, 0);
            
            for(int end_row = start_row; end_row < n; end_row++)
            {
                
                
                for(int col = 0; col < m; col++)
                {
                    col_array[col] += matrix[end_row][col];
                }
                
               
                
                int curr_max = find_max(col_array, k);
                
               
                
                maxi = max(maxi, curr_max);
            }
        }
        
        return maxi;
    }
};
