class Solution {
public:
bool check(vector<vector<int>>& mat, int row, int col){
    int ans=0;
      for(int i=0; i<mat.size(); i++){
          if(mat[i][col]==1){
              ans++;
          }
      }
      for(int j=0; j<mat[0].size(); j++){
          if(mat[row][j]==1){
              ans++;
          }
      }
      if(ans==2) return true;
      return false;
}
    int numSpecial(vector<vector<int>>& mat) {
        int count=0;
        int temp=0;
        int ans=0;
        vector<int> v;
        vector<int> c;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1){
                    if(check(mat, i ,j)) ans++;

                }
            }
        }
return ans;

    }
};