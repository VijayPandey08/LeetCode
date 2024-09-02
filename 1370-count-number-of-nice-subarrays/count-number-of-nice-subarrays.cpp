class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;

        int total = 0;

        int count = 0;

        map<int, int> m; // kitne odd numbers vale kitne khiladi h
        m[0] = 1;

        while (right < nums.size()) {

            if (nums[right] % 2 != 0) {
                count++;
            }

            m[count]++;

            if (m.find(count - k) != m.end()) {
                total += m[count - k];
            }

            right++;
        }

        for(auto i:m){
            cout<<i.first<<i.second<<endl;
        }

        return total;
    }
};