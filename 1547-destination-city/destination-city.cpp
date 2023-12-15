// class Solution {
// public:
//     string destCity(vector<vector<string>>& paths) {
//         string ans="";
//         vector<string> s;
//         vector<string> t;
//         for(int i=0; i<paths.size(); i++){
//             s.push_back(paths[i][0]);
//         }
//         for(int i=0; i<paths.size(); i++){
//             t.push_back(paths[i][1]);
//         }
//         for(auto i:s){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//         //     for(auto i:t){
//         //     cout<<i<<" ";
//         // }
//         // cout<<endl;
//         sort(s.begin(),s.end());
//         for(auto i:s){
//             cout<<i<<" ";
//         }
// cout<<endl;
// //  for(int i=0; i<t.size(); i++){
// //      for(int j=0; j<s.size(); j++){
// //          if()
// //      }
// //  }
     




//         // set<string> a;
//         // for(auto i:s){
//         //     a.insert(i);
//         // }
//         // for(auto i:t){
//         //     a.insert(i);
//         // }
//         // for(auto i:a){
//         //     cout<<i<<" ";
//         // }
//         // cout<<endl;
//         return 0;
//     }
// };
class Solution {
public:
    string destCity(vector<vector<string>>& p) {

        unordered_map<string,int> m;
        vector<string> v;


        for(int i=0;i<p.size();i++){
            m[p[i][0]]++;
            m[p[i][1]]++;
        }

        for(auto i:m){
            if(i.second==1){
                v.push_back(i.first);
            }
        }

        for(int i=0;i<p.size();i++){
            if(p[i][0]==v[0]){
                return v[1];
            }
            else if(p[i][1]==v[0]){
                return v[0];
            }
        }
        return 0;
        
    }
};