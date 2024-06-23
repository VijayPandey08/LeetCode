class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        // multiset is a dataset which has following benifits
        // 1-> can keep elements in sorted order
        // 2-> can keep duplicate elements
        // 3-> can keep delete specific element by reaching that index
        int n = nums.size();
        int max_length =0;

        multiset<int> s;
        
        // khandani sliding windown
        int i=0;
        int j=0;
        
        while(j<n){
            s.insert(nums[j]); // sorted fashion m multiset m dalo

            while(*s.rbegin() - *s.begin()>limit){  // max aur min ka difference jb tk limit se bda h, tb tk 'i' aage bdhate jaao
                s.erase(s.find(nums[i]));
                i++;
            }
            // max_length maintain krte chalo
            max_length = max(max_length,j-i+1);
            j++;
        }

        return max_length;
    }
};