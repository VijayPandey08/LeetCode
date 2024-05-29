class Solution {
public:
    int numSteps(string s) {
        if (s.length() == 1)
            return 0;
        int ans = 0;
        while (s.length() > 1) {
            if (s.back() == '0') {
                ans++;
                s.pop_back();
                if(s.length()==1) return ans;

            } else {
                ans++;
                for (int i = s.length() - 1; i > 0; i--) {
                    if (s[i] == '1') {
                        s.pop_back();
                        ans++;

                    }
                    else{
                        break;
                    }
                }
                if(s.back()=='1') ans++;
                s[s.length()-1] = '1';
            }
            cout<<s<<endl;
        }
        return ans ;
    }
};