class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size()-1;
        vector<vector<int>> result(n+1,vector<int>(n+1));
        for(int i =0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                 result[j][n-i]=matrix[i][j];
            }
        }
        matrix=result;
        return ;
    }
};