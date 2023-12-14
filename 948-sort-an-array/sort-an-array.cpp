class Solution
{
    public:

        void merge(vector<int> &nums, int s, int e)
        {
            int mid=s+(e-s)/2;
            int lenLeft = mid - s + 1;
            int lenRight = e - mid;
            int *left = new int[lenLeft];
            int *right = new int[lenRight];
            int k = s;
            for (int i = 0; i < lenLeft; i++)
            {
                left[i] = nums[k];
                k++;
            }
            k = mid + 1;
            for (int i = 0; i < lenRight; i++)
            {
                right[i] = nums[k];
                k++;
            }

            int indLeft = 0;
            int indRight = 0;
            int actual = s;

            while (indLeft < lenLeft && indRight < lenRight)
            {
                if (left[indLeft] < right[indRight])
                {
                    nums[actual] = left[indLeft];
                    actual++;
                    indLeft++;
                }
                else
                {
                    nums[actual] = right[indRight];
                    actual++;
                    indRight++;
                }
            }

            while (indLeft<lenLeft){
                nums[actual]=left[indLeft];
                actual++;
                indLeft++;
            }
                while (indRight<lenRight){
                nums[actual]=right[indRight];
                actual++;
                indRight++;
            }

            delete[] left;
            delete[] right;
        }
    void mergeSort(vector<int> &nums, int s, int e)
    {
        if (s >= e)
        {
            return;
        }
        int mid = s + (e - s) / 2;

        mergeSort(nums, s, mid);
        mergeSort(nums, mid + 1, e);
        merge(nums, s, e);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();
        int s = 0;
        int e = nums.size() - 1;
        mergeSort(nums, s, e);
        return nums;
    }
};