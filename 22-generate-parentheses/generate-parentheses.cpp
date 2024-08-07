class Solution {
public:
vector<string> ans;

void solve(int n, int open, int close, string temp){
    if(temp.length()==2*n){
        ans.push_back(temp);
        return;
    }

    if(open<n){
        solve(n,open+1,close,temp+"(");
    }
    if(close<open ){   // master stroke
        solve(n,open,close+1,temp+")");
    }

}

    vector<string> generateParenthesis(int n) {
        int open=0;
        int close=0;
        string temp="";

        solve(n,open,close,temp);
        return ans;
    }
};