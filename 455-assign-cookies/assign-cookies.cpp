class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        if(s.size()==0 || g.size()==0) return 0;
        if(g[0]>s[s.size()-1]) return 0;

        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j < g.size(); j++) {
                if (s[i] >= g[j] && g[j]!=-1) {
                    ans++;
                    g[j] = -1;
                    break;
                }
            }
        }
        return ans;
    }
};