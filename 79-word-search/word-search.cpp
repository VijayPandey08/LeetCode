class Solution {
public:
    bool solve(vector<vector<char>>& board, int i, int j, int idx,
               string word) {
        if (idx == word.length()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] == '$') {
            return false;
        }

        if (board[i][j] != word[idx]) {
            return false;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        bool up = solve(board, i - 1, j, idx + 1, word);
        bool down = solve(board, i + 1, j, idx + 1, word);
        bool left = solve(board, i, j - 1, idx + 1, word);
        bool right = solve(board, i, j + 1, idx + 1, word);

        board[i][j] = temp;

        return up | down | left | right;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // string temp = "";
        int idx = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    bool ans = solve(board, i, j, idx, word);
                    if (ans)
                        return true;
                }
            }
        }

        return false;
    }
};