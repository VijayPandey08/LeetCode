class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;  // answer store krne k lie

        map<int,int> m;  // har element ki frequency check krne k lie
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

 vector<pair<int, int>> v;  // frequency aur original number ek sath dalne ke lie
 for(auto i:m){
     v.push_back({i.second,i.first}); // pehle frequency daali q ki uski ke hisab se sort krna pdega
 }

   sort(v.begin(),v.end()); // sort kr dia frquency wise

   reverse(v.begin(),v.end()); // ascending ko descending order m convert kr dia...
   

   for(int i=0; i<k; i++){
       ans.push_back(v[i].second); // sirf original number ko answer mein dala, q ki vo pair mein dusre int mein stored tha
   }

        return ans;
    }
};