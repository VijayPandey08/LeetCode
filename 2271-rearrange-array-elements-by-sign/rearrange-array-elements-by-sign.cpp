class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
            // brute force
            // vector<int> pos;
            // vector<int> neg;
            // for(int i=0; i<nums.size(); i++){
            //     if(nums[i]>0){
            //         pos.push_back(nums[i]);
            //     }
            //     else{
            //         neg.push_back(nums[i]);
            //     }
            // }
            // for(int i=0; i<pos.size(); i++){
            //     nums[2*i]=pos[i];
            //     nums[(2*i) + 1]=neg[i];
            // }


            // optimal approach
            vector<int> ans(nums.size(),0);
            int p=0;
            int n=1;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]>0){
                    ans[p]=nums[i];
                    p+=2;
                }
                else{
                    ans[n]=nums[i];
                    n+=2;
                }
            }
            return ans;
    }
};