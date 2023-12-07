class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            vector<int> temp;
            vector<int> ans;
            temp = nums;

            sort(nums.begin(), nums.end());

            int s = 0;
            int e = nums.size() - 1;

            int check1 = 0;
            int check2 = 0;

            while (s < e)
            {
                int mid = nums[s] + nums[e];
                if (mid == target)
                {
                    check1 = nums[s];
                    check2 = nums[e];
                    break;
                
                }
                else if (mid > target)
                {
                    e--;
                }
                else if (mid < target)
                {
                    s++;
                }
            }

            for (int i = 0; i < temp.size(); i++)
            {
                if (temp[i] == check1)
                {
                    ans.push_back(i);
                    break;
                }
            }
            for (int i = temp.size() - 1; i >= 0; i--)
            {
                if (temp[i] == check2)
                {
                    ans.push_back(i);
                    break;
                }
            }

            return ans;
        }
};