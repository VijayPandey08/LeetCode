class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(vector<int> candidates, int target, int index,
               vector<int> temp) {

        // base case no problem
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        // standard base case, note to stop if target is less than 0
        if (index >= n || target < 0) {
            return;
        }

        temp.push_back(candidates[index]); // inclusion
        solve(candidates, target - candidates[index], index,
              temp); // important catch agar kisi element ko include kr rhe h,
                     // toh acche se usme ghus jaao, index aage nhi badaenge, q
                     // ki baar baaar le skte h vo element;

        temp.pop_back(); // backtracking
        solve(candidates, target, index + 1,
              temp); // agar element nhi lia tbhi aage bdenge aur index+1 krenge
                     // aur frr vapas recursion ki madad se bar baar vo element
                     // lenge ya nhi lenge
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        int index = 0;
        vector<int> temp;

        solve(candidates, target, index, temp);

        return ans;
    }
};