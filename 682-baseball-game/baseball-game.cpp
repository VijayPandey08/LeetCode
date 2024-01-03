class Solution
{
    public:
        int calPoints(vector<string> &operations)
        {
            stack<int> s;
            for (int i = 0; i < operations.size(); i++)
            {
                // string<char> c = operations[i];
                if (s.size() > 1 && operations[i] == "+")
                {
                    int temp = s.top();
                    s.pop();
                    int next = s.top() + temp;
                    s.push(temp);
                    s.push(next);
                }
                else if (!s.empty() && operations[i] == "D")
                {
                    int temp = s.top();
                    s.push(2 *temp);
                }
                else if (!s.empty() && operations[i] == "C")
                {
                    s.pop();
                }
                else{
                    
                    s.push(stoi(operations[i]));
                }
            }
            int ans=0;
            while(!s.empty()){
                int temp=s.top();
                s.pop();
                ans+=temp;
            }
            return ans;
        }
};