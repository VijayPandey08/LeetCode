class Solution
{
    public:
        int n;

    void backtrack(int idx, vector<int> &nums, vector<vector< int >> &result, vector< int > &curr)
    {
        if (curr.size() >= 2)
        {
            result.push_back(curr);
        }
        unordered_set<int> st;
        for (int i = idx; i < n; i++)
        {
            if ((curr.empty() || nums[i] >= curr.back()) && (st.find(nums[i]) == st.end()))
            {
                curr.push_back(nums[i]);
                backtrack(i+1, nums,result,curr);
                curr.pop_back();
                st.insert(nums[i]);
            }
        }
    }
    vector<vector < int>> findSubsequences(vector<int> &nums)
    {
        n = nums.size();
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(0, nums, result, curr);
        return result;
    }
};