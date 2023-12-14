class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
           	//             int n = a.size();
           	//     if (n == 0) return 0;

           	//     int longest = 1;
           	//     unordered_set<int> st;
           	//    	//put all the array elements into set:
           	//     for (int i = 0; i < n; i++) {
           	//         st.insert(a[i]);
           	//     }

           	//    	//Find the longest sequence:
           	//     for (auto it : st) {
           	//        	//if 'it' is a starting number:
           	//         if (st.find(it - 1) == st.end()) {
           	//            	//find consecutive numbers:
           	//             int cnt = 1;
           	//             int x = it;
           	//             while (st.find(x + 1) != st.end()) {
           	//                 x = x + 1;
           	//                 cnt = cnt + 1;
           	//             }
           	//             longest = max(longest, cnt);
           	//         }
           	//     }
           	//     return longest;

           	// }

            if (nums.size() == 0) return 0;
           	//  if(nums.size()==1) return 1;
            int maxi = 1;

            int ans = 1;

            set<int> s;
            for (auto i: nums)
            {
                s.insert(i);
            }
            vector<int> temp;
            for (auto i: s)
            {
                temp.push_back(i);
            }
            // if (temp.size() == 1) return 1;
            sort(temp.begin(), temp.end());

            for (auto i: temp)
            {
                cout << i << " ";
            }
            cout << endl;
            for (int i = 1; i < temp.size(); i++)
            {
                if (temp[i] - temp[i - 1] == 1)
                {
                    ans++;
                    maxi = max(maxi, ans);
                }
                else
                {
                    ans = 1;
                }
            }
            return maxi;

           	//         vector<int> temp;
           	//        	// map<int,int > m;
           	//        	// for(auto i: nums){
           	//        	//     m[i]++;
           	//        	// }
           	//         sort(nums.begin(),nums.end());
           	//         int ans=1;
           	//           for(int i=1; i < nums.size(); i++){
           	//             if(nums[i]-nums[i-1]==1){
           	//                	// temp.push_back(nums[i]);
           	//                	// cout<<temp.size()<<" "<<endl;
           	//                 ans++;
           	//                 maxi=max(maxi,ans);
           	//             }
           	//             else{
           	//             ans=0;
           	//             temp.clear();
           	//             }

           	//         }
           	//        	// for(auto i: m){
           	//        	//     if(i.second<=1){
           	//        	//        return maxi+1;
           	//        	//     }
           	//        	//     else{
           	//        	//         return maxi;
           	//        	//     }
           	//        	// }

           	// return maxi;

           	    }
        };