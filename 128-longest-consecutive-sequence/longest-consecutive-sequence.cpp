class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            if(nums.size()==0) return 0;
            set<int> s;
            for(auto i:nums){
                s.insert(i);
            }

            nums.clear();

            for(auto i:s){
                nums.push_back(i);
            }
            // sort(nums.begin(), nums.end());
      
            
            int n = nums[0];
        
            int count = 1;
            int maxi=INT_MIN;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i]-n == 1)
                {
                    count++;
                }
                else{
                    count=1;
                }
                maxi=max(maxi,count);
           
                n=nums[i];
            
            }

            return maxi;
        }
};