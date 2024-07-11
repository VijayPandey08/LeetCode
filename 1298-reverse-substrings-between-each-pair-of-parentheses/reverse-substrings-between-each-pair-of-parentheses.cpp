class Solution {
public:
    string reverseParentheses(string s) {
        //------approach 1-----------//

        // stack<int> reverseLen;

        // string ans="";

        // for(auto i:s){
        //     if(i=='('){
        //         reverseLen.push(ans.length());
        //     }
        //     else if(i==')'){
        //         int len = reverseLen.top();
        //         reverseLen.pop();
        //         reverse(ans.begin()+len,ans.end());
        //     }
        //     else{
        //         ans.push_back(i);
        //     }
        // }

        // return ans;

        //----------approach -2---------------//

        stack<int> pairIdx;
        vector<int> pair(s.length());

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                pairIdx.push(i);
            } else if (s[i] == ')') {
                int idx = pairIdx.top();
                pairIdx.pop();
                pair[i] = idx;
                pair[idx] = i;
            }
        }

        int direction = 1;
        string ans = "";
        for (int i = 0; i < s.length(); i += direction) {
            if (s[i] == '(' || s[i] == ')') {
                i = pair[i];
                direction = -direction;
            } else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};