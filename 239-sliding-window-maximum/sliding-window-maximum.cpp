class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
            vector<int> ans;
            deque<int> dq;
           	///pehli window process kro
            for (int i = 0; i < k; i++)
            {
                int element = nums[i];
               	// jitne bhi queue k andar chote elements h remove kr do
                while (!dq.empty() && element > nums[dq.back()])
                {
                    dq.pop_back();
                }
               	//now insert kardo
                dq.push_back(i);
            }
           	/// remaing window ko process kro
           	// removal2 types
           	// addition
            for (int i = k; i < nums.size(); i++)
            {
               	//ans store kro
                ans.push_back(nums[dq.front()]);
               	// removal out of range
                if (!dq.empty() && i - dq.front() >= k)
                {
                    dq.pop_front();
                }
               	// removal chote vale
                int element = nums[i];
                while (!dq.empty() && element > nums[dq.back()])
                {
                    dq.pop_back();
                }
               	//addition
                dq.push_back(i);
            }
        
           	//last winow ka answer store karna pdega
            ans.push_back(nums[dq.front()]);
            return ans;
        }
};