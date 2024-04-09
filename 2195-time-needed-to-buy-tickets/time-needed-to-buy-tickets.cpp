class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans = 0;
        int times = tickets[k];
        while(times--){
            // if(temp == 0 )break;
        for(int i=0; i<tickets.size(); i++){
                int temp = tickets[k];
                if(temp == 0) break;
                if(tickets[i]>0){
                    ans++;
                    tickets[i]--;
                }
        }
        }
        return ans;

    }
};