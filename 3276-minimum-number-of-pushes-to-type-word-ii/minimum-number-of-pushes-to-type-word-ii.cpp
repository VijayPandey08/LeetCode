class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> m;
        for (auto i : word) {
            m[i]++;
        }
        int ans = 0;
        int count = 1;

        // for(auto i:m){
        //     cout<<i.first<<" "<<i.second;
        // cout<<endl;
        // }
        vector<int> vec;
        for (auto i : m) {
            
            vec.push_back(i.second);
            // p.make_pair({i.second,i.first});
        }

        sort(vec.rbegin(), vec.rend());

        // for (auto i : vec) {
        //     cout << i.first << " " << i.second;
        //     cout << endl;
        // }
// int count=0;

        for(int i = 0;i<vec.size();i++){
            ans+= vec[i]* ((i+1+7)/8);
        }


        return ans;
    }
};