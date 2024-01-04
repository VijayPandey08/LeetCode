#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        bool isInteger(const string &s)
        {
            if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
            {
                return false;
            }

            char *p;
            strtol(s.c_str(), &p, 10);

            return (*p == 0);
        }

    int evalRPN(vector<string> &token)
    {
        stack<int> s;
        for (int i = 0; i < token.size(); i++)
        {
            if (s.size() > 1 && token[i] == "+")
            {
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.pop();
                s.push(temp1 + temp2);
            }
            else if (s.size() > 1 && token[i] == "-")
            {
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.pop();
                s.push(temp2 - temp1);	// Corrected order of subtraction
            }
            else if (s.size() > 1 && token[i] == "*")
            {
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.pop();
                s.push(temp1 *temp2);
            }
            else if (s.size() > 1 && token[i] == "/")
            {
                int temp1 = s.top();
                s.pop();
                int temp2 = s.top();
                s.pop();
                s.push(temp2 / temp1);	// Corrected order of division
            }
            else if (isInteger(token[i]))
            {
                s.push(stoi(token[i]));
            }
        }
        return s.top();
    }
};