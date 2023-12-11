class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int ans=0;

        map<int,int> m;
        for(int i=0; i<arr.size(); i++){
            m[arr[i]]++;
        }

vector<pair<int,int>> v;
 for(auto i: m){
     v.push_back({i.second,i.first});
 }

sort(v.begin(),v.end());

//    for(auto i:v){
//        cout<<i.first<<" "<<i.second<<endl;
//    }
ans=v[v.size()-1].second;
        return ans;
    }
};