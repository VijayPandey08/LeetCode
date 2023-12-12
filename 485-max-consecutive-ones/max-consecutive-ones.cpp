class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int count=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1){
                count++;
                ans=max(ans,count); // yeh ans ko hum else mein nhi update kra skte q ki agar last element one hoga, toh vo else statemnet m ghusega hi nhi.. aur hamara cut jaaega
            }
            else{
            count=0;
            }
        }
        return ans;
    }
};