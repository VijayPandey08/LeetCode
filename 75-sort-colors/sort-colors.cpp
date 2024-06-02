class Solution {
public:
    void sortColors(vector<int>& nums) {
        // hi -fi question h, angrejo ki bhansha mein, dutch national flag algorithm mein based
        int s=0;  // yeh starting pointer h, ise bs zero se matlab h
        int m=0; // yeh h asli khiladi, pura iterate krega jo shi dhng se
        int e=nums.size()-1; // yeh high pointer h ise bs 2 se mtlb h

        while(m<=e){
            if(nums[m]==0){
                swap(nums[s],nums[m]);
                    m++;
                    s++;
            }
            else if(nums[m]==1){
                m++;
            }
            else{
                swap(nums[m],nums[e]);
                e--;
            }
        }
        return ;
    }
};