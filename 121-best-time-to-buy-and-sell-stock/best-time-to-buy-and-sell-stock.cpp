class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int buy=prices[0];
       int sell=0;
       int profit=INT_MIN;
       for(int i=0; i<prices.size(); i++){
           if(buy>prices[i]){
               buy=prices[i];
           }
           else{
               profit=max(profit,prices[i]-buy);
           }
       } 
       return profit;
    }
};