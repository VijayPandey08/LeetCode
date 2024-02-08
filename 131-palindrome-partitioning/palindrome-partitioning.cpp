class Solution {
public:
vector<vector<string>> ans;
vector<string> curr;
bool check(string s,int l,int r){

    while(l<r){
        if(s[l++]!=s[r--]){
            return false;
        }
    }
    return true;
}
void solve(int idx, string s){
if(idx>=s.length()){
    ans.push_back(curr);
    return;
}
for(int i=idx; i<s.length(); i++){
    if(check(s,idx,i)){
        curr.push_back(s.substr(idx,i-idx+1));
        solve(i+1,s);
        curr.pop_back();
    }
}

}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        string temp="";
        solve(0,s);
        return ans;
    }
};