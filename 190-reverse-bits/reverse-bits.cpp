class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans=0;
        vector<int> v;
        for(int j=0; j<32; j++){
            v.push_back(n&1);
            n=n>>1;
        }
        reverse(v.begin(),v.end());

        for(int i=0; i<v.size(); i++){
            ans+=v[i]*(pow(2,i));
        }
         return ans;
    }
};