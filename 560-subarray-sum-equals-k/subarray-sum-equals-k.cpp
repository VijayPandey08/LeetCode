class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        m[0]++;
        int sum = 0;
        int ans = 0;
        for(auto i:nums){
            sum+=i;
            if(m.find(sum-k)!=m.end()) ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};