class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        // intution: need to maintain record of the max profit along with the
        // difficulty so we use priority queue and take entry in pair

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < profit.size(); i++) {
            pq.push({profit[i], difficulty[i]});
        }

        // this is important step to reverse the worker ability to do a work, so
        // that we can pop entries from the pq which no worker can complete
        sort(worker.rbegin(), worker.rend());

        // basic initialisation
        int total_profit = 0;
        int i = 0;

        // normally tracking the max_profitability and adding it to the
        // total_progitability
        while (i < worker.size() && !pq.empty()) {
            int max_profit = 0;
            if (worker[i] < pq.top().second) {
                pq.pop();
            } else {
                max_profit = max(max_profit, pq.top().first);
                i++;
            }
            total_profit += max_profit;
        }

        // return answer at last
        return total_profit;
    }
};