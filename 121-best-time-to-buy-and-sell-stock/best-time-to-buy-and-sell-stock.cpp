class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // brute forces toh yehi hota ki tum do looop lagate aur dekh lete kha
        // pr difference zada h, pr esa kr nhi skte q ki, constraint 10^8 se
        // uppar nikal jaaenge do for loop se


        // yeh bdiya jugadu tareeka h, q ki ek hi iteration mein kaam poora krna h
        int ans = 0;
        int buy = prices[0]; // maanlo ki pehla hi khareed lia h

        // ab iske next element se iteration se shuru kro
        // agar kam ka huea toh seedha use khareed lena

        // agar zada ka bik raha ho toh profit store kr lena, aur aage bdhna 

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];    
            } else if (prices[i] > buy) {
                ans = max(ans, abs(prices[i] - buy));
            }
        }
        return ans;
    }
};