class Solution {
public:
    bool isGood(vector<int>& nums) {
        int size = nums.size();
        
        int maxi =INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi = max(maxi,nums[i]);
        }
        
        int req = maxi + 1;
        
        if(size> req || size<req){
            return false;
        }
        
        sort(nums.begin(),nums.end());
        
        map<int,int> m;
        
        if(nums[0]==1 && nums[nums.size()-2]==maxi && nums[nums.size()-1]==maxi){
            return true;
        }
        return false;
    }
};