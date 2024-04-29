class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(auto i:nums){
            ans = ans^i;
        }
        int cnt = 0;
        while(k || ans){
            if((k&1) != (ans&1)){
                cnt++;
            }
            k = k>>1;
            ans = ans>>1;
        }
        return cnt;
        
    }
};