class Solution {
public:
int result=0;
int solve(int i, int j, vector<vector<int>> &v){
     if(i==0 && j==0){
         result++;
         return 1;
     }
     if(i<0 || j<0){
         return 0;
     }
     if(v[i][j]!= 0){
         return v[i][j];
     }
     
     return v[i][j] = solve(i,j-1,v)+ solve(i-1,j,v);
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m+1,vector<int>(n+1,0));
        return solve(m-1,n-1,v);
        
    }
};