class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=0;
        vector<int> v;
        for(int i=0; i<n; i++){
            int entery = (start + (2*i));
            v.push_back(entery );
        }
        for(auto i:v){
            ans=ans^i;
        }
        return ans;
    }
};