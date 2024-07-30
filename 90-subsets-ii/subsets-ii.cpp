// class Solution {
// public:
// vector<vector<int>> ans;

// void solve(vector<int>& nums, int n, int index, vector<int> temp){
//     if(index>=n){
//         ans.push_back(temp);
//         return;
//     }
//     temp.push_back(nums[index]);
//     solve(nums,n,index+1,temp);
    
//     solve(nums,n,index+1,temp);

// }

//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         vector<int> temp;
//         int n =nums.size();
//         int index = 0;

//         solve(nums,n,index,temp);
        
//         set<vector<int>> s;
//         for(auto i:ans){
//             s.insert(i);
//         }
//         vector<vector<int>> result;
//         for(auto i:s){
//             result.push_back(i);
//         }
//         return result;

//     }
// };

#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> ans;

    void solve(std::vector<int>& nums, int n, int index, std::vector<int> temp) {
        if (index >= n) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        solve(nums, n, index + 1, temp);
        temp.pop_back(); // Backtrack
        solve(nums, n, index + 1, temp);
    }

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        ans.clear(); // Clear previous results
        std::sort(nums.begin(), nums.end()); // Sort the input to handle duplicates
        std::vector<int> temp;
        int n = nums.size();
        int index = 0;

        solve(nums, n, index, temp);
        
        std::set<std::vector<int>> s(ans.begin(), ans.end()); // Use set to remove duplicates
        std::vector<std::vector<int>> result(s.begin(), s.end()); // Convert set to vector
        
        return result;
    }
};


// class Solution {
// public:
//     vector<vector<int>> ans;

//     void solve(vector<int>& nums, int n, int index, vector<int> temp) {
//         if(index >= n) {
//             ans.push_back(temp);
//             return;
//         }
//         solve(nums, n, index + 1, temp);
//         temp.push_back(nums[index]);
//         solve(nums, n, index + 1, temp);
//     }

//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         ans.clear();  // Clear previous results
//         sort(nums.begin(), nums.end());  // Sort the input to handle duplicates
//         vector<int> temp;
//         int n = nums.size();
//         int index = 0;

//         solve(nums, n, index, temp);

//         // Remove duplicates
//         sort(ans.begin(), ans.end());
//         ans.erase(unique(ans.begin(), ans.end()), ans.end());

//         return ans;
//     }
// };
