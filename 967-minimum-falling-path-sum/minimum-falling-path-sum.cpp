class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        for(int i = 1;i<n;i++){
            for(int j = 0;j<m;j++){
                int mini = arr[i-1][j];
                if(j-1>=0) mini = min(mini,arr[i-1][j-1]);
                if(j+1<m) mini = min(mini,arr[i-1][j+1]);
                arr[i][j]+=mini;
            }
        }

        return *min_element(arr[n-1].begin(),arr[n-1].end());
    }
};