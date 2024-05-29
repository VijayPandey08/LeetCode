class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> start1(1, 1);
        vector<int> start2(2, 1);
        ans.push_back(start1);
        if(numRows==1) return ans;
        ans.push_back(start2);
        for (int i = 3; i <= numRows; i++) {
            vector<int> temp = ans[i - 2];
            vector<int> temp1(i, 1);
            temp1[0] = 1;
            temp1[i - 1] = 1;
            for (int j = 1; j < i - 1; j++) {
                temp1[j] = temp[j - 1] + temp[j];
            }
            ans.push_back(temp1);
        }
        return ans;
    }
};