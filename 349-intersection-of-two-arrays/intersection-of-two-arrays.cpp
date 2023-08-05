class Solution
{
    public:
        vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
        {
            vector<int> v;
            set<int> s;
            for (auto i: nums1)
            {
                s.insert(i);
            }
            set<int> p;
            for (auto i: nums2){
                p.insert(i);
            }

            vector<int> v1;
            vector<int> v2;

            for(auto i: s){
                v1.push_back(i);
            }
            for(auto i: p){
                v2.push_back(i);
            }

            for(int i=0; i<v1.size(); i++){
                for(int j=0; j<v2.size(); j++){
                    if(v1[i]==v2[j]){
                        v.push_back(v1[i]);
                    }
                }
            }

            return v;
        }
};