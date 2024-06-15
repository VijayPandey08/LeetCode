class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<pair<int, int>> v;
        for (int i = 0; i < profits.size(); i++) {
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        int i = 0;
        priority_queue<int> pq;
        int n = capital.size();
        while (k) {
            if (i<n && w >= v[i].first ) {
                pq.push(v[i].second);
                i++;
            } else {
                if (pq.size() == 0)
                    return w;
                w += pq.top();
                pq.pop();
                k--;
            }
        }
        return w;
    }
};