//It is implementing interpolation Search in C++;
#include <iostream>

//It is function for interpolation Search
//It is kind of similar to binary search, but it has different equation to decide position for mid value
int ISearch(int arr[], int first, int last, int target) {

	int mid;

	//If value with first index is bigger than target
	//if value with last index is smaller than target
	//it returns -1 to exit function
	if (arr[first]>target || arr[last] <target) {
		return -1;
	}

	//It is main part for this search algorithm
	//We use double to have accuarte value for mid value
	//We consider fisrt index is low, last index is high, index with value we want to find is s
	//We consider A as difference between first value and last value A=(arr[high] - arr[low])
	//We consider Q as difference between first value and value we want to find Q=(arr[s]-arr[low])
	//Based on Proportion, we can have A:Q = (high-low):(s-low)
	//By changing it into normal equation, we can have s=Q/A(high-low)+low
	//If we consider arr[s] = x, finally we can have s = (x-arr[low]/(arr[high]-arr[low]))(high-low)+low
	mid = ((double)(target - arr[first]) / (arr[last] - arr[first]) * (last - first)) + first;

	//When our first value with mid index has target, just return mid
	if (arr[mid] == target) {
		return mid;
	}
	//When target is smaller than the value we found, we only need to consider range from first to mid-1
	//When target is bigger than the value we found, we only need to consider tange from mid+1 to last
	else if (target < arr[mid]) {
		return ISearch(arr, first, mid - 1, target);
	}
	else {
		return ISearch(arr, mid + 1, last, target);
	}

}


int main() {

	int arr[8] = { 2,3,4,5,6,7,8,9};
	//int arr[3] = { 3, 3, 3 };

	int arrsize = sizeof(arr) / sizeof(arr[0]);


	int idx=ISearch(arr, 0, arrsize-1,5);


	if (idx == -1) {
		std::cout << "There is no value you are looking for in array" << std::endl;
	}
	else {
		std::cout << "Index for value you are looking for is " << idx << std::endl;
	}


}



