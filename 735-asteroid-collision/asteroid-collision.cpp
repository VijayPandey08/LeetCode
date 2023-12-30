class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
                vector<int> ans;
        stack<int> s;
        
        for (int i = 0; i < ast.size(); i++) {
            if (s.empty() || ast[i] > 0) {
                s.push(ast[i]);
            } else {
                while (!s.empty() && s.top() > 0) {
                    int topAsteroid = s.top();
                    s.pop();
                    
                    if (abs(topAsteroid) == abs(ast[i])) {
                        // Both asteroids annihilate each other
                        ast[i] = 0;
                        break;
                    } else if (abs(topAsteroid) > abs(ast[i])) {
                        // Top asteroid survives, push it back to stack
                        s.push(topAsteroid);
                        ast[i] = 0;
                        break;
                    }
                    // Current asteroid survives, keep checking with the remaining stack
                }
                if (ast[i] != 0) {
                    // If current asteroid is not annihilated, push it to stack
                    s.push(ast[i]);
                }
            }
        }

        // Transfer remaining asteroids from stack to the result
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        // Reverse the result to maintain the order
        reverse(ans.begin(), ans.end());

        return ans;

    }
};