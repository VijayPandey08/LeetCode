class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangles) {

        for (int i = 1; i < triangles.size(); i++) {
            for (int j = 0; j < triangles[i].size(); j++) {
                int ans = INT_MAX;
                if (j < triangles[i - 1].size()) {
                    ans = min(ans, triangles[i - 1][j]);
                }
                if (j - 1 >= 0) {
                    ans = min(ans, triangles[i - 1][j - 1]);
                }

                triangles[i][j] += ans;
            }
        }
        return *min_element(triangles[triangles.size() - 1].begin(),
                            triangles[triangles.size() - 1].end());
    }
};