class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int ans=0;

       vector<int> pre;
       vector<int> suf;

       pre.push_back(nums[0]);
       suf.push_back(nums[nums.size()-1]);

       for(int i=1; i<nums.size(); i++){
           pre.push_back(pre[i-1]+nums[i]);
       } 

       for(int i=1; i<nums.size(); i++){
        suf.push_back(suf[i-1]+nums[nums.size()-i-1]);
       }
       reverse(suf.begin(),suf.end());
           if(nums.size()==1) return 0;
           if(suf[1]==0){
               return 0;
           }
       for(int i=1; i<nums.size()-1; i++){
           if(pre[i-1]==suf[i+1]) return i;

       }
           if(pre[nums.size()-2]==0) return nums.size()-1;

          return -1;

    }
};