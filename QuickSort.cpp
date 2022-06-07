//It is implementing QuickSort in C++;
#include <iostream>


//It is function to swap two values in array with index
void swap(int arr[], int idx1, int idx2) {

	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;


}

//It is function for partition, so values are traded based on pivot here.
int partition(int arr[], int left, int right) {

	//In the quick sort, we need low and high
	//Low is left + 1 because left means pivot in this case
	//high is right here
	//pivot is value with left index
	int low = left + 1;
	int high = right;
	int pivot = arr[left];

	//While low is less than equal high, it keep repeating
	//It means it is over when low and high cross over.
	while (low <= high) {

		//Increasing low value until it finds higher value than pivot
		//In case of array has same value in it, we need to decide boundary for it
		while (pivot >= arr[low] && low<=right) {
			low++;
		}

		//Decreasing high value until it finds lower value than pivot
		//In case of array has same value in it, we need to decide boundary for it
		while (pivot <= arr[high] && high >= (left + 1)) {
			high--;
		}

		//If low is still less tha equal to high, swap two values
		//One value is bigger value than pivot with low index
		//Another vlaue is smaller value than pivot with high value
		if (low <= high) {
			swap(arr, low, high);
		}
	}

	//After low and high cross over, we need to swap values in pivot and high
	//Therefore, pivot can find its own place
	//For next step, we need to return high index used for pivot, so it is index for pivot for now
	swap(arr, left, high);
	return high;
}

//It is function that repeats to sort values in the array
void quicksort(int arr[], int left, int right) {

	//if left becomes bigger than right, it exits function, so it is condition to exit resursion
	//Based on pivot, we keep diving into two parts and find places for pivot for each case
	if (left <= right) {
		int pivot = partition(arr, left, right);
		quicksort(arr, left, pivot - 1);
		quicksort(arr, pivot + 1, right);
	}

}



int main() {

	int arr[8] = { 3,2,4,1,7,6,5,8};
	//int arr[3] = { 3, 3, 3 };

	int arrsize = sizeof(arr) / sizeof(arr[0]);


	quicksort(arr, 0, arrsize-1);


	for (int i = 0; i < arrsize; i++) {
		std::cout << arr[i] << std::endl;
	}


}


