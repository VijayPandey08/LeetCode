class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;

        map<int,int> m;

        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }

        for(auto i:m){
            if(i.second>n/3){
                result.push_back(i.first);
            }
        }
        return result;
    }
};