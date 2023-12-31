class Solution
{
    public:
    bool check(int a, int b,vector<vector < char>> &board ){
         map<char,int> m;
         for(int i=a; i<a+3; i++){
                for(int j=b; j<b+3; j++){
                    if(board[i][j]!='.') m[board[i][j]]++;
                    if (m[board[i][j]] > 1) return false;
                }
            }
            m.clear();
            return true;

    }
        bool isValidSudoku(vector<vector < char>> &board)
        {



            map<char, int> m;

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if(board[i][j]!='.') m[board[i][j]]++;
                    if (m[board[i][j]] > 1) return false;
                }
                m.clear();
            }


            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if(board[j][i]!='.') m[board[j][i]]++;
                    if (m[board[j][i]] > 1) return false;
                }
                m.clear();
            }
     

     
     if(!(check(0,0,board))) return false;
     if(!(check(3,0,board))) return false;
     if(!(check(6,0,board))) return false;
     if(!(check(0,3,board))) return false;
     if(!(check(3,3,board))) return false;
     if(!(check(6,3,board))) return false;
     if(!(check(0,6,board))) return false;
     if(!(check(3,6,board))) return false;
     if(!(check(6,6,board))) return false;

            // int a,b;
            // a=0;
            // b=0;
            // for(int i=a; i<a+3; i++){
            //     for(int j=b; j<b+3; j++){
            //         if(board[i][j]!='.') m[board[i][j]]++;
            //         if (m[board[i][j]] > 1) return false;
            //     }
            // }
            // m.clear();

            // a=0;
            // b=3;
            // for(int i=a; i<a+3; i++){
            //     for(int j=b; j<b+3; j++){
            //         if(board[i][j]!='.') m[board[i][j]]++;
            //         if (m[board[i][j]] > 1) return false;
            //     }
            // }
            // m.clear();

            // a=0;
            // b=6;
            // for(int i=a; i<a+3; i++){
            //     for(int j=b; j<b+3; j++){
            //         if(board[i][j]!='.') m[board[i][j]]++;
            //         if (m[board[i][j]] > 1) return false;
            //     }
            // }
            // m.clear();

            // a=3;
            // b=0;
            // for(int i=a; i<a+3; i++){
            //     for(int j=b; j<b+3; j++){
            //        if(board[i][j]!='.') m[board[i][j]]++;
            //         if (m[board[i][j]] > 1) return false;
            //     }
            // }
            // m.clear();

            // a=3;
            // b=3;
            // for(int i=a; i<a+3; i++){
            //     for(int j=b; j<b+3; j++){
            //        if(board[i][j]!='.') m[board[i][j]]++;
            //         if (m[board[i][j]] > 1) return false;
            //     }
            // }
            // m.clear();


            // a=3;
            // b=6;
            // for(int i=a; i<a+3; i++){
            //     for(int j=b; j<b+3; j++){
            //       if(board[i][j]!='.') m[board[i][j]]++;
            //         if (m[board[i][j]] > 1) return false;
            //     }
            // }
            // m.clear();

            // a=6;
            // b=0;
            // for(int i=a; i<a+3; i++){
            //     for(int j=b; j<b+3; j++){
            //        if(board[i][j]!='.') m[board[i][j]]++;
            //         if (m[board[i][j]] > 1) return false;
            //     }
            // }
            // m.clear();

            // a=6;
            // b=3;
            // for(int i=a; i<a+3; i++){
            //     for(int j=b; j<b+3; j++){
            //       if(board[i][j]!='.') m[board[i][j]]++;
            //         if (m[board[i][j]] > 1) return false;
            //     }
            // }
            // m.clear();

            // a=6;
            // b=6;
            // for(int i=a; i<a+3; i++){
            //     for(int j=b; j<b+3; j++){
            //         if(board[i][j]!='.') m[board[i][j]]++;
            //         if (m[board[i][j]] > 1) return false;
            //     }
            // }
            // m.clear();

            return true;

        }
};