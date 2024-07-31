class Solution {
public:
    vector<vector<int>> ans;
    int len;

    // ------------------ approach 1 ----------------------//
    // k numbers uthane h 1 se 9 ke beech aur target banana h
    // intution based chale 1 se 9 ka nums array bana dia, aur base case dekh
    // lia ki jb exactly k numbers ho aur target zero ho jaae tab hi add krnaa h
    // classic backtrcking

    void solve(vector<int>& nums, int index, int k, int target,
               vector<int> temp) {

        // base case
        if (temp.size() == k && target == 0) {
            ans.push_back(temp);
            return;
        }
        if (index >= len) {
            return;
        }

        temp.push_back(nums[index]); // inclusion
        solve(nums, index + 1, k, target - nums[index], temp);

        temp.pop_back(); // backtracking exclusion
        solve(nums, index + 1, k, target, temp);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        //
        vector<int> nums;
        for (int i = 1; i <= 9; i++) {
            nums.push_back(i);
        }
        len = nums.size();
        int index = 0;

        vector<int> temp;
        solve(nums, index, k, n, temp);
        return ans;
    }
};

// ------------- approach 2 ---------------------//
// variables zada ho rhe the toh isme kam variables use kre, jab numbers uthane
// 1 se 9 ke beech h, aur vo bhi at most ek baar toh nums array na bana ke, ek
// hi variable m kaam kr dia, ya toh index lenge ya nhi lenge, baki sb at it is

// class Solution {
// public:
//     vector<vector<int>> ans;
//     int len;

//     void solve(int index, int k, int target, vector<int> temp) {

//         // base case
//         if (temp.size() == k && target == 0) {
//             ans.push_back(temp);
//             return;
//         }
//         if (index > len) {
//             return;
//         }

//         temp.push_back(index); // inclusion
//         solve(index + 1, k, target - index, temp);

//         temp.pop_back(); // backtracking exclusion
//         solve(index + 1, k, target, temp);
//     }

//     vector<vector<int>> combinationSum3(int k, int n) {
//         len = 9;
//         int index = 1;

//         vector<int> temp;
//         solve(index, k, n, temp);
//         return ans;
//     }
// };