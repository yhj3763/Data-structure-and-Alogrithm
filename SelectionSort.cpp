//It is implementing Selection Sort in C++
#include <iostream>

//It is function for Selection sort.
//It gets array and size of array as parameters
void selectionsort(int arr[], int n) {

	//Make two variables for moving and sorting
	int temp;
	int sorted;

	//For loop outside, it is considered as number of values that are sorted, so it starts from 0 to n - 1
	//Because when we sort n - 1 values, last value is sorted automatically 
	for (int i = 0; i < n - 1; i++) {

		//initialize sorted variable with i 
		//i means the place we need to store value after we sort value
		sorted = i;

		//For loop inside, we need to start from n + 1 because we already store i value in sorted 
		//i value means the place we need to store value and value before i means the values that are sorted already
		for (int j = i + 1; j < n; j++) {
			
			//If arr[sorted] has bigger number than arr[j], we need to change value in sorted to j
			if (arr[sorted] > arr[j]) {
				sorted = j;
			}
		}

		//After we finish sorting for the value, we need to change values in the place we need to store value
		//Therefore, arr[i] has sorted value in it, and arr[sorted] has any value stored in arr[i] before we sorted
		temp = arr[i];
		arr[i] = arr[sorted];
		arr[sorted] = temp;
	}

}



int main() {

	int arr[5] = { 2, 5, 1, 4, 3 };

	int arrsize = sizeof(arr) / sizeof(arr[0]);

	selectionsort(arr, arrsize);

	for (int i = 0; i < arrsize; i++) {

		std::cout << arr[i] << std::endl;
	}



}
