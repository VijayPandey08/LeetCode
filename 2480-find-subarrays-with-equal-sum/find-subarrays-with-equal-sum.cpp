class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        if(nums.size()<3) return false;
        map<int,int> m;

        for(int i=1; i<nums.size(); i++){
            m[nums[i]+nums[i-1]]++;
        }

        for(auto i:m){
            if(i.second>=2) return true;
        }

        return false;
    }
};