class Solution
{
    public:
        vector<vector < string>> groupAnagrams(vector<string> &s)
        {
            vector<vector < string>> ans;
            
            map<string,vector<string>> m;
            for (auto i: s)
            {
                string j = i;
                sort(j.begin(), j.end());
                m[j].push_back(i);
            }
            for(auto i:m){
                ans.push_back(i.second);
            }
            return ans;
        }
};