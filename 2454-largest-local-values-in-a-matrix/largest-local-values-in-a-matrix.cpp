class Solution {
public:
int solve(vector<vector<int>>& grid, int a, int b){
    int temp =INT_MIN;
    for(int i=a; i<a+3; i++){
        for(int j=b; j<b+3; j++){
            temp = max(temp,grid[i][j]);
        }
    }
    return temp;
}
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int temp=INT_MIN;
        int n = grid.size();
        vector<vector<int>> v(n-2,vector<int>(n-2,0));
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
                v[i][j]=solve(grid,i,j);
            }
        }
   return v;
    }
};