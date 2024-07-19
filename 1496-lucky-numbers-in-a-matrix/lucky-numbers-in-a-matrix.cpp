class Solution {
public:
    vector<int> ans;
    void checkCol(vector<vector<int>>& matrix, int temp1, int temp2) {
        int maxi = INT_MIN;
        for (int i = 0; i < matrix.size(); i++) {
            maxi = max(maxi, matrix[i][temp2]);
        }

        if (matrix[temp1][temp2] == maxi) {
            ans.push_back(matrix[temp1][temp2]);
        }
    }
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int temp1 = -1;
        int temp2 = -1;
        for (int i = 0; i < n; i++) {
            int mini = INT_MAX;
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < mini) {
                    mini = matrix[i][j];
                    temp1 = i;
                    temp2 = j;
                }
            }
            checkCol(matrix, temp1, temp2);
        }
        return ans;
    }
};