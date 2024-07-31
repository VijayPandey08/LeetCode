
// another approach using for loop for determining loop , it is more optimized, unique find krne ke lie, duplicate hatane ke lie bdiya tarika h yeh,   vrna hume set banana pdega jo dikkat de skta h.....!!!
class Solution {
public:
    vector<vector<int>> ans;
    int n;

    void solve(vector<int>& nums, int idx, vector<int> tmp) {
         
            ans.push_back(tmp);
         
         for(int j=idx; j<n; j++) {
             if(j > idx && nums[j] == nums[j-1]) continue;
             tmp.push_back(nums[j]);
             solve(nums, j+1, tmp);
             tmp.pop_back();
         }
         
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         
         n = nums.size();
         sort(nums.begin(), nums.end());
         vector<int> tmp;
         solve(nums, 0, tmp); 

         return ans;
    }
};












// class Solution {
// public:
//     vector<vector<int>> ans;

//     void solve(vector<int>& nums, int n, int index, vector<int> &temp) {
//         if (index >= n) {
//             ans.push_back(temp);
//             return;
//         }
//         temp.push_back(nums[index]);
//         solve(nums, n, index + 1, temp);
//         temp.pop_back();
//         solve(nums, n, index + 1, temp);
//     }

//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         vector<int> temp;
//         int n = nums.size();
//         int index = 0;
//         sort(nums.begin(), nums.end());
//         solve(nums, n, index, temp);

//         set<vector<int>> s(ans.begin(), ans.end());
//         vector<vector<int>> result(s.begin(), s.end());

//         return result;
//     }
// };


