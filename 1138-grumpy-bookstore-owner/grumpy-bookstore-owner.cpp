#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int max_unsatisfied = 0;
        int curr_unsatisfied = 0;
        
        // Calculate initial unsatisfied customers in the first `minutes` window
        for (int i = 0; i < minutes; i++) {
            curr_unsatisfied += customers[i] * grumpy[i];
        }

        max_unsatisfied = curr_unsatisfied;

        // Sliding window to find the max unsatisfied customers we can turn to satisfied
        int i=0;
        int j=minutes;
        while (j < n) {
            curr_unsatisfied += customers[j] * grumpy[j]; 
            curr_unsatisfied -= customers[i] * grumpy[i];
            max_unsatisfied = max(max_unsatisfied, curr_unsatisfied);
            i++;
            j++;
        }

        
        int total_satisfied = max_unsatisfied;

        // Calculate the total satisfied customers without considering grumpy window
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                total_satisfied += customers[i];
            }
        }

        return total_satisfied;
    }
};
