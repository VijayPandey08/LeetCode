class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& arr, int n, int index, vector<int>& temp, int k) {

        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        if (index >= n) {
            return;
        }



        temp.push_back(arr[index]); // inclusion
        solve(arr, n, index + 1, temp, k); 

        temp.pop_back(); //backtracking or exclusion
        solve(arr, n, index + 1, temp, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
        }
        
        int s = arr.size();
        int index = 0;
        vector<int> temp;

        solve(arr, n, index, temp, k);
        return ans;
    }
};
