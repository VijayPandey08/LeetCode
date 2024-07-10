class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(auto i:logs){
            if(ans<0){
                ans=0;
            }
            if(i=="../"){
                ans--;
                continue;
            }
            if(i=="./"){
                continue;
            }
            else{
                ans++;
            }
        }
        if(ans<0) return 0;
        return ans;
    }
};