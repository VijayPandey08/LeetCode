class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            vector<int> temp=nums;
            vector<int> ans;
        

            sort(nums.begin(), nums.end());

            int s = 0;
            int e = nums.size() - 1;

            int check1 = 0;
            int check2 = 0;

            while (s < e)
            {
                
               
                if (nums[s]+nums[e] > target)
                {
                    e--;
                }
                else if (nums[s]+nums[e] < target)
                {
                    s++;
                }
                else{
                    check1=nums[s];
                    check2=nums[e];
                    break;
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