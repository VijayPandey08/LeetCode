class Solution
{
    public:
        vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
        {
            int n = nums2.size();
            vector<int> ans(n, -1);
            stack<int> s;
            for (int i = n - 1; i >= 0; i--)
            {
                while (!s.empty() && s.top() < nums2[i])
                {
                    s.pop();
                }
                if (!s.empty())
                {
                    ans[i] = s.top();
                }
                else
                {
                    ans[i] = -1;
                }
                s.push(nums2[i]);
            }
            map<int,int> m;
            for(int i=0; i<nums2.size(); i++){
                m[nums2[i]]=ans[i];
            }
            vector<int> final;
            for(auto i:nums1){
                final.push_back(m[i]);
            }
            return final;
        }
};