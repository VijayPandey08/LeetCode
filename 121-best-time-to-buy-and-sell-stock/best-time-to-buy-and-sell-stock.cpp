class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int ans=0;
        for(int i=0; i<prices.size(); i++){
            if(buy>prices[i]){
                buy=prices[i];
            }
            else if(buy<prices[i]){
                ans=max(ans,prices[i]-buy);
            }
        }
        return ans;
    }
};