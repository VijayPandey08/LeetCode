class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int count=1;
        for(int i=1; i<nums.size()-1; i++){
            if(ans==nums[i]){
                count++;
            }
            else{
                count--;
                if(count<=0){
                    ans=nums[i+1];
                }
            }

        }
        return ans;
    }
};