class Solution {
public:
    // void solve(vector<vector<int>>& result, vector<vector<int>>& meetings) {

    //     return;
    // }
    int countDays(int days, vector<vector<int>>& meetings) {
        // it is a simple add on to merge interval question

        // so let us merge the intervals first

        vector<vector<int>> result;
        // solve(result,meetings);

// -----------result vector----------------

        sort(meetings.begin(), meetings.end());
        vector<int> current;
        current = meetings[0];

        for (int i = 1; i < meetings.size(); i++) {
            if (current[1] >= meetings[i][0]) {
                current[0] = min(current[0], meetings[i][0]);
                current[1] = max(current[1], meetings[i][1]);
            } else {
                result.push_back(current);
                current = meetings[i];
            }
        }
        result.push_back(current);



for(auto i:result){
    cout<<i[0]<<" "<<i[1];
cout<<endl;
}

        int count = 0;
        for (auto i : result) {
            count += i[1] - i[0]+1;
        }
        return days - count;
    }
};