class Solution {
public:

void solve(vector<vector<int>>& temp, int row, int col){
    for(int i=0; i<temp.size(); i++){
            temp[i][col]=0;
    }
    for(int i=0; i<temp[0].size(); i++){
            temp[row][i]=0;
        
    }
}
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> temp;
        temp=matrix;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    solve(temp, i, j);
                    // for(int k=0; k<m; k++){
                    //     temp[i][k]=0;
                    // }
                }
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(matrix[i][j]==0){
        //             for(int k=0; k<n; k++){
        //                 temp[k][j]=0;
        //             }
        //         }
        //     }
        // }
        for(int i=0; i<n; i++){
         for(int j=0; j<m; j++){
            matrix[i][j]=temp[i][j];
         }
        }
        // return matrix;
    
    }
};