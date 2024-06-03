class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // in this we have to take extra space...
        // but we need to find a better approach in which no space is required
        // int n=matrix.size()-1;
        // vector<vector<int>> result(n+1,vector<int>(n+1));
        // for(int i =0; i<matrix.size(); i++){
        //     for(int j=0; j<matrix[0].size(); j++){
        //          result[j][n-i]=matrix[i][j];
        //     }
        // }
        // matrix=result;
        // return ;

        /// -------------- approach 2 --------------////
        // it is basically a observation based approach..
        // STEP 1: TAKE TRANSPOSE
        // STEP 2: REVERSE THE MATRIX
        // done...!

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < i; j++) {
                // for transpose we simply use swap function
                // transpose karna bhi apne aap mein ek kala hein..
                // prime diagonal chedhne ki zrurat nhi, j =0 se j< i tak hi
                // jaaaega----> very imp
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            // reverse krna h row ke hisab se...toh dekh lo, row tak iterate kia
            // haur matrix[i].begin(),matrix[i].end() maar dia
            reverse(matrix[i].begin(), matrix[i].end());
        }
        return;
    }
};