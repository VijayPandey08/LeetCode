class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int max_length =0;

        multiset<int> s;

        int i=0;
        int j=0;

        while(j<n){
            s.insert(nums[j]);

            while(*s.rbegin() - *s.begin()>limit){
                s.erase(s.find(nums[i]));
                i++;
            }

            max_length = max(max_length,j-i+1);
            j++;
        }

        return max_length;
    }
};