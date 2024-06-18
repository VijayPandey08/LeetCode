class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                            vector<int>& worker) {
        vector<pair<int, int>> v;

        for (int i = 0; i < profit.size(); i++) {
            v.push_back({difficulty[i], profit[i]});
        }

        sort(v.begin(), v.end());

        sort(worker.begin(), worker.end());

        int total_profit = 0;
        int max_profit = 0;

        int j = 0;

        for (int i = 0; i < worker.size(); i++) {
            while (j < profit.size() && worker[i] >= v[j].first) {
                max_profit = max(max_profit, v[j].second);
                j++;
            }
            total_profit += max_profit;
        }

        return total_profit;
    }
};