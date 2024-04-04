class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        // int close = 0;
        int ans=0;
        int maxi=INT_MIN;
        for(auto i:s){
            if(i=='('){
                ans++;
            }
            maxi=max(ans,maxi);
            if(i==')'){
                ans--;
            }
        }
        return maxi;
    }
};