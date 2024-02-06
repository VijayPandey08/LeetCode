class Solution
{
    public:
        int m, n;
    vector<vector < int>> directions
    {
        { 1,
            0 },
        { -1,
            0 },
        { 0,
            1 },
        { 0,
            -1 }
    };	// dorections vector pehle hi bana dia taake chaaro direction ke lie alag alaga call na krni pde
    bool find(vector<vector < char>> &board, int i, int j, int idx, string &word)
    {

        if (idx == word.length())
        {
            return true;
        }
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$')
        {
            return false;
        }
        if (board[i][j] != word[idx])
        {
            return false;
        }

        char temp = board[i][j];	// ek temp char banaya taki backtrac krte wqt vapas original char daal ske
        board[i][j] = '$';	// jha traverse kr dia aur char mil gya vha temporarily '$' daal dia taaki vapas na aae usi p
        for (auto &dir: directions)
        {
        	// for loop laga ke chaaaro direction traverse kr li
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (find(board, new_i, new_j, idx + 1, word))
            {
                return true;
            }
        }
        board[i][j] = temp;	// backtrack krte wqt temp ki shi value shi jagah daal di
        return false;	// agar last tak answer na mile toh false return karwa do
    }

    bool exist(vector<vector < char>> &board, string word)
    {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == word[0] && find(board, i, j, 0, word))
                {
                    return true;
                }
            }
        }

        return false;
    }
};