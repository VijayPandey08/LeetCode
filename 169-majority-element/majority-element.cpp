class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int s = nums.size();
        int n = (s/2) +1;
        cout<<n;

        for(int i=0; i<s; i++){
            if(m[nums[i]]>=n){
                return nums[i];
            }
        }
        return 0;
    }
};