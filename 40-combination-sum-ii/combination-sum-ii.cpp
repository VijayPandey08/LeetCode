class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(vector<int>& candidates, int target, int index, vector<int>& temp) {
        // standard base cases
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0) {
            return;
        }

        // duplicate hatane ke lie for loop best h, pehle hi sorted candidates array bheja h, ab same same element m continue maar denge, aur backtracking bhi vhi ki vhi ho jaaegi
        for (int i = index; i < n; i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue; // skip duplicates
            temp.push_back(candidates[i]);// inclusion


            solve(candidates, target - candidates[i], i + 1, temp);

            temp.pop_back();// backtracking
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // sort candidates
        n = candidates.size();
        vector<int> temp;
        int index = 0;

        solve(candidates, target, index, temp);
        return ans;
    }
};
