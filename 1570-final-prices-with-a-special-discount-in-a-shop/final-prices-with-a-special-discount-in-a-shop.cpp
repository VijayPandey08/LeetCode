class Solution
{
    public:
        vector<int> finalPrices(vector<int> &prices)
        {
            int n = prices.size();
            vector<int> ans(n);
            stack<int> st;
            st.push(0);
            for (int i = n - 1; i >= 0; i--)
            {
                int curr = prices[i];
               	// answer find krte h ab
                while (st.top() > curr)
                {
                    st.pop();
                }
            
            ans[i] = (curr - st.top());
            st.push(curr);
            }
            return ans;
        }
};