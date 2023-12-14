class Solution {
public:

void merge(vector<int>& nums, int s, int e) {

	int mid = (s+e)/2;

	int lenLeft = mid - s + 1;
	int lenRight = e - mid;

	//create left and right array
	int *left = new int[lenLeft];
	int *right = new int[lenRight];

	//copy values from original array to left array
	int k = s;
	//k -> starting index of left array values in original arrya
	for(int i=0; i<lenLeft; i++) {
		left[i] = nums[k];
		k++;
	}

	//copy values from original array to right array
	k = mid+1;
	for(int i=0; i<lenRight; i++) {
		right[i] = nums[k];
		k++;
	}

	//actual merge logic here
	//left array is already sorted
	//right array is already sorted
	int leftIndex = 0;
	int rightIndex = 0;
	//yahi pr galti karte h log
	int mainArrayIndex = s;

	while(leftIndex < lenLeft &&  rightIndex < lenRight) {
		
		if(left[leftIndex] < right[rightIndex] ) {
			nums[mainArrayIndex] =  left[leftIndex];
			mainArrayIndex++;
			leftIndex++;
		}
		else {
			nums[mainArrayIndex] =  right[rightIndex];
			mainArrayIndex++;
			rightIndex++;
		}
	}


	//2 more cases

	//1 case -> left array exhaust but right array me element abhi bhi bache hai
	while(rightIndex < lenRight) {
		nums[mainArrayIndex] =  right[rightIndex];
		mainArrayIndex++;
		rightIndex++;
	}
	

	//2nd case -> rigght array exhaust but left array me element abhi bhi bache hai
	while(leftIndex < lenLeft) {
		nums[mainArrayIndex] =  left[leftIndex];
		mainArrayIndex++;
		leftIndex++;
	}
	//1 more step pending
	delete[] left;
	delete[] right;
}

void mergeSort(vector<int>& nums, int s, int e) {
	//base case
	if(s >= e) {
		return;
	}
	//break
	int mid = (s+e)/2;
	//recusive call for left array
	mergeSort(nums,s, mid);
	//recusive call for right array
	mergeSort(nums, mid+1, e);
	//merge 2 sorted arrays
	merge(nums, s, e);
}
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=nums.size()-1;
        
        mergeSort(nums,s,e);
        return nums;
    }
};