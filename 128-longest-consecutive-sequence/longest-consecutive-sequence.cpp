class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
 
 //------------little bit more optimised------
        int ans = 0;
        int count = 1;

        unordered_set<int> s; // we are using set data structure here

        for(auto i:nums){
            s.insert(i);
        }

        for(auto i:s){
 // logic agar kisi number ke peeche vala number maujud h toh q na peeche vaale se hi check kre           
            if(s.find(i-1)!=s.end()){ 
                continue;
            }
            else{
                while(s.find(i+1)!=s.end()){
                    count++;
                    i++;   // yeh mt bhulo janab
                }
                ans=max(ans,count);
                count=1;
            }

        }
        return ans;
    }
};