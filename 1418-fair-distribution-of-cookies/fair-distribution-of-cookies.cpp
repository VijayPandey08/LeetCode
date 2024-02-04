class Solution
{
    public:
        int result = INT_MAX;
    int n;

    void solve(int idx, std::vector<int> &cookies, std::vector<int> &children, int k)
    {
        if (idx >= n)
        {
            int unfairness = *std::max_element(children.begin(), children.end());
            result = std::min(result, unfairness);
            return;
        }

        int cookie = cookies[idx];
        for (int i = 0; i < k; i++)
        {
            children[i] += cookie;
            solve(idx + 1, cookies, children, k);
            children[i] -= cookie;
        }
    }

    int distributeCookies(std::vector<int> &cookies, int k)
    {
        n = cookies.size();
        std::vector<int> children(k);
        int idx = 0;
        solve(idx, cookies, children, k);
        return result;
    }
};