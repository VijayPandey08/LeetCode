class Solution {
public:
    string reverseParentheses(string s) {
        //------approach 1-----------//

        stack<int> reverseLen;

        string ans="";

        for(auto i:s){
            if(i=='('){
                reverseLen.push(ans.length());
            }
            else if(i==')'){
                int len = reverseLen.top();
                reverseLen.pop();
                reverse(ans.begin()+len,ans.end());
            }
            else{
                ans.push_back(i);
            }
        }

        return ans;
    }
};