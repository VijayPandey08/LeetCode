class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> temp;
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr2[i] == arr1[j]) {
                    temp.push_back(arr1[j]);
                }
            }
        }

        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < arr1.size(); j++) {
                if (arr2[i] == arr1[j]) {
                    arr1[j] = -1;
                }
            }
        }
        vector<int> temp1;
        for (int i = 0; i < arr1.size(); i++) {
            if (arr1[i] != -1) {
                temp1.push_back(arr1[i]);
            }
        }

        sort(temp1.begin(), temp1.end());

        for (int i = 0; i < temp1.size(); i++) {
            temp.push_back(temp1[i]);
        }
        arr1 = temp;
        return arr1;
    }
};