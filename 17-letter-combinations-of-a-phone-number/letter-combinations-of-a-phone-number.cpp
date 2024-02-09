class Solution {
public:
int n;
vector<string> result;
map<char,string> m;
string curr;

// if(digits.length==0) return "";
void solve(int idx, string digits){
    if(curr.length()==n && digits.length()>0){
        result.push_back(curr);
        return;
    }
    string word = m[digits[idx]];
    for(int i=0; i<word.length(); i++){
        curr.push_back(word[i]);
        solve(idx+1,digits);
        curr.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        n = digits.length();
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        // string curr="";
        solve(0,digits);
        return result;
    }
};