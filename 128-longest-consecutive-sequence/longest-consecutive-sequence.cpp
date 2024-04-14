class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;

        set<int> s;
        for(auto i: nums){
            s.insert(i);
        }
        int ans=1;
        vector<int> temp;
        for(auto i:s){
            temp.push_back(i);
        }
        int val=1;
        for(int i=1; i<temp.size(); i++){
            if(temp[i]-temp[i-1]==1){
                val++;
                ans=max(ans,val);

            }
            else{
                val=1;
            }
         }
         return ans;
    }
};