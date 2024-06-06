class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> m;

        for(auto i: hand){
            m[i]++;
        }

        for(auto it=m.begin(); it!=m.end(); it++){
            int val = it->first;
            int freq = it->second;

            if(freq>0){
                for(int i=0; i<groupSize; i++){
                    if(m[val+i]<freq){
                        return false;
                    }
                    m[val+i]-=freq;
                }
            }
        }
        return true;
    }
};