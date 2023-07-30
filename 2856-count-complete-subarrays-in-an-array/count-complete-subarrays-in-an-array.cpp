class Solution
{
    public:
        int countCompleteSubarrays(vector<int> &nums)
        {
            int ans = 0;
            vector<int> v;
            map<int,int> s;

            for (auto i: nums)
            {
                s[i]++;
            }
            int size = s.size();

            for (int i = 0; i < nums.size(); i++)
            {
                map<int,int> s1;
                for (int j = i; j < nums.size(); j++)
                {
                    s1[nums[j]]++;
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