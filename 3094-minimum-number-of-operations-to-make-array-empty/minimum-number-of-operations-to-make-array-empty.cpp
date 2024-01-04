class Solution
{
    public:
        int minOperations(vector<int> &nums)
        {
            int ans = 0;
            sort(nums.begin(), nums.end());
            if(nums[nums.size()-1]!=nums[nums.size()-2]) return -1;
      
           	// map<int,int > m;
            int count = 1;
            for (int i = 0; i < nums.size() - 1; i++)
            {
                if (nums[i] == nums[i + 1])
                {
                    count++;
                }
                else
                {
                    
                    if (count == 1) return -1;
                    if (count % 3 != 0)
                    {
                        ans += (count / 3) + 1;
                        count = 1;
                    }
                    else
                    {
                        ans += (count / 3);
                        count = 1;
                    }
                }
            
            }
                if (count % 3 != 0)
                {
                    ans += (count / 3) + 1;
                    count = 1;
                }
                else
                {
                    ans += (count / 3);
                    count = 1;
                }
            return ans;
        }
};