class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        stack<int> s;
        s.push(-1);

        vector<int> ans(n2, -1);

        s.push(nums2[n2 - 1]);

        for (int i = n2 - 2; i >= 0; i--) {
            while (nums2[i] > s.top() && s.top() != -1) {
                s.pop();
            }
            ans[i] = s.top();
            s.push(nums2[i]);
        }

        vector<int> final(nums1.size(),-1);

        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    final[i] = ans[j];
                }
            }
        }

        return final;
    }
};