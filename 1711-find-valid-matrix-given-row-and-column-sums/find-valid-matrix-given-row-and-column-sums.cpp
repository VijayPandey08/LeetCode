class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        vector<vector<int>> v(rowSum.size(), vector<int>(colSum.size(), 0));

        int i = 0; // for row
        int j = 0; // for cool

        while (i < rowSum.size() && j < colSum.size()) {
            v[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= v[i][j];
            colSum[j] -= v[i][j];

            if (rowSum[i] == 0)
                i++;
            if (colSum[j] == 0)
                j++;
        }
        return v;
    }
};