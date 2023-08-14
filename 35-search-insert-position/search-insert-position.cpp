class Solution
{
    public:
        int searchInsert(vector<int> &nums, int target)
        {
            int s = 0;
            int e = nums.size() - 1;
            int ans = 0;

            while (s <= e)
            {
                int mid = e - ((e-s)/2);
                // ans = mid;
                if (target > nums[mid])
                {   
                    s = mid + 1;
                    ans=s;
                
                }
                else if (target < nums[mid])
                {   
                    e = mid - 1;
                    ans=e;
                
                }
                else
                {
                    return mid;
                }
            }

            if(ans<0){
                return 0;
            }
            if(ans>nums.size()-1){
                return ans;
            }
            else{
                if(nums[ans]>target){
                    return ans;
                }
                else{
                    return ans +1;
                }
            }

            // return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        }
};