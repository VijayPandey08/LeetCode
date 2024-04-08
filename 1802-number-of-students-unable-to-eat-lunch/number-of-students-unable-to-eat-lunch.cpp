class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> count(2,0);
        for(auto i: students){
            if(i==0){
                count[0]++;
            }
            else{
                count[1]++;
            }
        }
        int ans = sandwiches.size();
        for(auto i : sandwiches){
            if(i == 1){
                if(count[1]==0) {
                    break;
                }
                else{
                count[1]--;
                ans--;
                }
            }
            if(i == 0){
                if(count[0]==0){
                    break;
                }
                else{
                count[0]--;
                ans--;
                }
            }
        }
        return ans;
    }
};