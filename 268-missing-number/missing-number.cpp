class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> v;
        int k=0;
        for(int i=0; i<nums.size()+1; i++){
            v.push_back(k);
            k++;
        }
        

        sort(nums.begin(),nums.end());


        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=v[i]){
                return v[i];
            }
        }
        return nums.size();
    }
};