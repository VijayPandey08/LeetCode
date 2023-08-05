class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        vector<int> ans;
        int n= nums.size();
        map<int,int> m;

        for(int i=0; i<n; i++){
            m[nums[i]]++;
        }
        
        for(int i=1; i<n+1; i++){
            if(m[i]==0){
                ans.push_back(i);
            }
        }

        return ans;
    }
};