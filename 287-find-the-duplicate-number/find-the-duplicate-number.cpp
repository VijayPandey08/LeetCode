class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // we will use here and tortoise algorithm
        // observation : duplicate numbers
        
        // here and tortoise algorithm simply helps in detection a cycle
        // and determining the start of the circle

        // first time fast == slow : cycle is present
        // then from here move slow to zero, then move fast and slow by one space each and when again they will meet i.e fast == slow then this will be the required ans
        // return fast/slow

// STEP 1 : MOVING SLOW one space... and FAST two space
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];


//STEP-2 : DETECTING CYCLE
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

// STEP 3 : After cycle is confirmed, bring slow back to start
        slow = nums[0];


// STEP 4:  move both slow and fast one one space to find starting point of cylcle
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
        // return slow;
        
    }
};