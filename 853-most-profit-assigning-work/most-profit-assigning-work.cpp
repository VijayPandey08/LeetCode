class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<profit.size(); i++){
            pq.push({profit[i],difficulty[i]});
        }

        // sort(pq.begin(),pq.end());

        sort(worker.rbegin(),worker.rend());


         int total_profit=0;
            int i=0;
            while(i<worker.size() && !pq.empty()){
            int max_profit=0;
                  if(worker[i]<pq.top().second){
                    pq.pop();
                  }
                  else{
                    max_profit=max(max_profit,pq.top().first);
                    i++;
                  }
            total_profit+=max_profit;
        }
        return total_profit;
    }
};