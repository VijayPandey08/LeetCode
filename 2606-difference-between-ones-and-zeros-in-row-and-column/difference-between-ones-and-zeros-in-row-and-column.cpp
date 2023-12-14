class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        vector<int> temp1;
        vector<int> temp2;
        
 
 
        
        
        for(int i=0; i<m; i++){
            int count1=0;
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    count1++;
                }
            }
            temp1.push_back(count1);
        }
                
        
               for(int i=0; i<n; i++){
                   int count2=0;
            for(int j=0; j<m; j++){
                if(grid[j][i]==1){
                    count2++;}
            }
                   temp2.push_back(count2);
               }
           
         
                
                for(int i=0; i<m; i++){
                    for(int j=0; j<n; j++){
                        ans[i][j]= temp1[i] + temp2[j] - (m-temp1[i]) - (n-temp2[j]);
                    }
                }
                
 
        return ans;
    }
};