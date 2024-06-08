class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        // Find the maximum skill value
        int maxi = *max_element(skills.begin(), skills.end());

        // If k is greater than or equal to the number of players, the player with maximum skill wins
        if (k >= skills.size()) {
            return find(skills.begin(), skills.end(), maxi) - skills.begin();
        }

        deque<int> q(skills.begin(), skills.end());
        unordered_map<int, int> win_count;
        int current_winner = 0;

        while (true) {
            int a = q.front(); q.pop_front();
            int b = q.front(); q.pop_front();

            if (a > b) {
                win_count[a]++;
                if (win_count[a] >= k) {
                    current_winner = a;
                    break;
                }
                q.push_front(a);
                q.push_back(b);
            } else {
                win_count[b]++;
                if (win_count[b] >= k) {
                    current_winner = b;
                    break;
                }
                q.push_front(b);
                q.push_back(a);
            }
        }

        return find(skills.begin(), skills.end(), current_winner) - skills.begin();
    }
};
