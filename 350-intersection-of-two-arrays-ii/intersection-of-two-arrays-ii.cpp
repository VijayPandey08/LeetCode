class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<pair<int, int>> v1;
        map<int, int> m1;
        for (int i = 0; i < nums1.size(); i++) {
            m1[nums1[i]]++;
        }

        for (auto i : m1) {
            v1.push_back({i.first, i.second});
        }

        vector<pair<int, int>> v2;
        map<int, int> m2;
        for (int i = 0; i < nums2.size(); i++) {
            m2[nums2[i]]++;
        }

        for (auto i : m2) {
            v2.push_back({i.first, i.second});
        }

        vector<int> v;
        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                if (v1[i].first == v2[j].first) {
                    int count = min(v1[i].second, v2[j].second);
                    while (count--) {
                        v.push_back(v1[i].first);
                    }
                }
            }
        }
        return v;
    }
};