class Solution
{
    public:
        int countCompleteSubarrays(vector<int> &nums)
        {
            int ans = 0;
            vector<int> v;
            set<int> s;

            for (auto i: nums)
            {
                s.insert(i);
            }
            int size = s.size();

            for (int i = 0; i < nums.size(); i++)
            {
                set<int> s1;
                for (int j = i; j < nums.size(); j++)
                {
                    s1.insert(nums[j]);
                    if (s1.size() == size)
                    {
                        ans = ans + nums.size() - j;
                        break;
                    }
                }
            }
            return ans;
        }
};