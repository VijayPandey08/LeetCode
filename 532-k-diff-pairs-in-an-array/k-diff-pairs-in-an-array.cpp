class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>> p;
        int ans=0;
        int s=0;
        int e=0;
        sort(nums.begin(),nums.end());
        while( e<nums.size()){
          if(abs(nums[e]-nums[s])==k){
              if(s!=e) {p.insert({nums[e],nums[s]});
              s++;
              e++;}
              else{
                  e++;
              }

          }
          else if(abs(nums[e]-nums[s])>k){
              s++;
          }
          else if(abs(nums[e]-nums[s])<k){
              e++;
          }
        }
        return p.size();
    }
};