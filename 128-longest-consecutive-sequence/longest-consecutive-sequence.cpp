class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

//------aproach one basic se thoda better--------//

        if(nums.size()==0) return 0; // standard case 

        int ans = 1;     // isse max maintain krenge
        int count = 1;   // iterate krte hue kaam aaaega

        sort(nums.begin(),nums.end()); // standard proceudure


        for(int i=1; i<nums.size(); i++){
            if(abs(nums[i]-nums[i-1])==1){
                count++;
                ans = max(ans,count);
            }
            else if(nums[i]==nums[i-1]){
                continue;
            }
            else{
                count=1;
            }
        } 
        return ans;
        
    }
};