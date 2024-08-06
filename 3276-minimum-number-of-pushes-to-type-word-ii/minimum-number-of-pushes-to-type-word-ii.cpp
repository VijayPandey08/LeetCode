class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> m;
        for (auto i : word) {
            m[i]++;
        }
        int ans = 0;

        // for(auto i:m){
        //     cout<<i.first<<" "<<i.second;
        // cout<<endl;
        // }
        vector<int> vec;
        for (auto i : m) {   
            vec.push_back(i.second);
        }

        sort(vec.rbegin(), vec.rend());
        
        int count = 1;
        int val = 1;
        for(auto i:vec){
            ans+= i*val;
            if(count%8 == 0) val++;
            count++;
        }


        return ans;
    }
};