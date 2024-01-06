class Solution
{
    public:
        bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
        {
            stack<int> s;

            int n = pushed.size();
        int m = popped.size();
        int j = 0;

        for (int i = 0; i < n; ++i) {
            s.push(pushed[i]);

            while (!s.empty() && j < m && s.top() == popped[j]) {
                s.pop();
                ++j;
            }
        }

        return j == m && s.empty();
        }
};