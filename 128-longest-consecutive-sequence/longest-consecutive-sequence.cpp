class Solution {
public:
    int longestConsecutive(vector<int>& nums) {


        int ans = 0;
        int count = 1;

        unordered_set<int> s;

        for(auto i:nums){
            s.insert(i);
        }

        for(auto i:s){
            if(s.find(i-1)!=s.end()){
                continue;
            }
            else{
                while(s.find(i+1)!=s.end()){
                    count++;
                    i++;
                }
                ans=max(ans,count);
                count=1;
            }

        }
        return ans;
    }
};