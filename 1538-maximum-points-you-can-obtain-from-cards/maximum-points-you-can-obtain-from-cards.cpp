class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n = card.size();
        vector<int> pre(n, -1);

        pre[0] = card[0];

        for (int i = 1; i < n; i++) {
            pre[i] = card[i] + pre[i - 1];
        }

        int left = 0;
        int right = n - k;
        int mini = 0;
        for (int i = 0; i < right; i++) {
            mini+= card[i];
        }
        int temp = mini;
        cout<<mini<<" "<<temp;
        while (right < n) {
            temp+= card[right];
            temp-= card[left];
            mini = min(mini, temp);
            right++;
            left++;
        }

        int total = accumulate(card.begin(), card.end(), 0);

        return total - mini;
    }
};