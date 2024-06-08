class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int maxi = INT_MIN;
        for (auto i : skills) {
            maxi = max(maxi, i);
        }

        if (k >= skills.size()) {

            for (int i = 0; i < skills.size(); i++) {
                if (maxi == skills[i])
                    return i;
            }
        }

        vector<pair<int, int>> p;
        deque<int> q;
        for (auto i : skills) {
            q.push_back(i);
        }
        map<int, int> m;
        int temp = 0;
        while(true) {
            int a = q.front();
            q.pop_front();
            int b = q.front();
            q.pop_front();
            if (a > b) {
                m[a]++;
                if (m[a] >= k) {
                    temp = a;
                    break;
                }
                q.push_front(a);
                q.push_back(b);
            } else {
                m[b]++;
                if (m[b] >= k) {
                    temp = b;
                    break;
                }
                q.push_front(b);
                q.push_back(a);
            }
        }

        for (int i = 0; i < skills.size(); i++) {
            if (skills[i] == temp) {
                return i;
            }
        }
        return 0;
    }
};