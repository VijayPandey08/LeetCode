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
                int mid = (s+e)/2;


                cout<<mid<<endl;
                ans = mid;


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
                    // cout<<ans<<endl;
                    cout<<s<<" "<<e<<" "<<ans<<endl;
                    return ans;
                }
            }
            cout<<s<<" "<<e<<" "<<ans<<endl;
            // return ans+1;
            
            // if(nums[ans]<target){
            //     return ans+1;
            // }
            // else{
            //     return ans;
            // }
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
            // return 0;

            // return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        }
};