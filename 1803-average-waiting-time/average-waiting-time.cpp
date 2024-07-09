class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        vector<int> temp;
        int start = customers[0][0];
        for (auto i : customers) {
            if (start < i[0]) {
                start = i[0];
                start += i[1];
                temp.push_back(start - i[0]);
            } else {
                start += i[1];
                int temp1 = start - i[0];
                temp.push_back(temp1);
            }
        }
        double total = 0;
        for (auto i : temp) {
            total += i;
        }

        double size = customers.size();
        double ans = total / customers.size();
        return ans;
    }
};