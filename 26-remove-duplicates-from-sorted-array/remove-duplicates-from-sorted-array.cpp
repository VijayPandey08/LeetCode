class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        set<int> s;
        for(auto i : nums){
            s.insert(i);
        }
        for(auto i : nums){
            nums.pop_back();
        }
        for(auto i : s){
            nums.push_back(i);
        }
        k=s.size();
        return k;
    }
};