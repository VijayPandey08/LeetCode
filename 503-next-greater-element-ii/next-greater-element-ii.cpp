class Solution
{
    public:
        vector<int> nextGreaterElements(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> ans(n, -1);
            stack<int> s;
           	// s.push(-1);
            for (int i = 2*n - 1; i >= 0; i--)
            {

                while (!s.empty() && s.top() <= nums[i % n])
                {
                    s.pop();
                }
                if (i < n)
                {
                    if(!s.empty())
                    {
                        ans[i%n]= s.top();
                    }
                }
                    s.push(nums[i % n]);
            }
            return ans;


    //   int n = nums.size();
    //   vector < int > ans(n, -1);
    //   stack < int > st;
    //   for (int i = 2 * n - 1; i >= 0; i--) {
    //     while (!st.empty() && st.top() <= nums[i % n]) {
    //       st.pop();
    //     }

    //     if (i < n) {
    //       if (!st.empty()) ans[i] = st.top();
    //     }
    //     st.push(nums[i % n]);
    //   }
    //   return ans;
        }
};