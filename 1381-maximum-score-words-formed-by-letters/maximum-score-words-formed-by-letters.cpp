class Solution {
public:
    int n;
    int max_score;

    void solve(int i, vector<int>& score, vector<string>& words, int currScore,
               vector<int>& freq) {
        int temp_score = 0;
        max_score = max(max_score, currScore);
        if (i >= n)
            return;
        vector<int> temp_freq = freq;
        int j = 0;
        while (j < words[i].length()) {
            char ch = words[i][j];

            temp_freq[ch - 'a']--;
            if (temp_freq[ch - 'a'] < 0)
                break;
            temp_score += score[ch - 'a'];

            j++;
        }
        if (j == words[i].length()) { // take
            solve(i + 1, score, words, currScore + temp_score, temp_freq);
        }
        //  no take
        solve(i + 1, score, words, currScore, freq);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        n = words.size();
        max_score = INT_MIN;

        vector<int> freq(26, 0);
        for (auto ch : letters) {
            freq[ch - 'a']++;
        }

        solve(0, score, words, 0, freq);
        return max_score;
    }
};