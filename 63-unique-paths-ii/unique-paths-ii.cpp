class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0]==1 || grid[m-1][n-1] == 1 ){
            return 0;
        }

grid[0][0]=1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) continue;
                if( grid[i][j]==1){
                    grid[i][j]=0;
                }
                else{
                    if(i-1>=0){
                        grid[i][j]+= grid[i-1][j];
                    }

                    if(j-1>=0){
                        grid[i][j]+= grid[i][j-1];
                    }

                }
            }
        }


        for(auto i:grid){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        return grid[m-1][n-1];
    }
};