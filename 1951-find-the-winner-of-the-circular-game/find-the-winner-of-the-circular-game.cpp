class Solution {
public:
    int findTheWinner(int n, int k) {
        // there are mainly three approaches to solve this question

 //         //--------approach 1 ------------// (using vector<int>)
        // vector<int> v;
        // for (int i = 1; i <= n; i++) {
        //     v.push_back(i);
        // }
        // int index = 0;
        // while (v.size() > 1) {
        //     index = index + k - 1;
        //     index = (index % v.size());
        //     v.erase(v.begin() + index);
        // }

        // return v[0];

        //-------approach 2------------// (using queue)
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }

        while (q.size() > 1) {
            for (int i = 0; i < k - 1; i++) {
                int temp = q.front();
                q.pop();
                q.push(temp);
            }
            q.pop();
        }

        return q.front();
    }
};