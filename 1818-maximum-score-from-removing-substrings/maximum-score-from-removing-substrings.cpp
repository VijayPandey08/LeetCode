class Solution {
public:

string gainStr(string &s, string str){
    stack<char> st;

    for(int i=0; i<s.length(); i++ ){
        if(!st.empty() && s[i]==str[1] && st.top()==str[0] ){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
    }

    string temp="";
    while(!st.empty()){
        char ch=st.top();
        temp.push_back(ch);
        st.pop();
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;
        string maxStr = x>=y?"ab":"ba";
        string minStr = x<y?"ab":"ba";

        //---------1st pass--------------//
        string firstStr = gainStr(s,maxStr);
        int len = firstStr.length();
        int pairs = (n-len)/2;
        score+=pairs*max(x,y);

        //---------2nd pass------------//
        string secondStr =gainStr(firstStr,minStr);
        int len2 = secondStr.length();
        pairs =(len-len2)/2;
        score+=pairs*min(x,y);



        return score;
    }
};