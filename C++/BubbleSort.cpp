//It is implementing Bubble Sort in C++
#include <iostream>

//It is function for bubble sort.
//It gets array and size of array as parameters
void bubblesort(int arr[], int n) {

	//Temp for moving value 
	int temp;

	//For loop outside, it can be considered as numbers that is sorted
	//When there are four values in the array, we need to sort three values and last value is sorted automatically when we finish sorting other three values
	for (int i = 0; i < n - 1; i++) {

		//For loop inside, it goes through all array 
		//If first value is bigger than second value, change them, so make biggest number move to at the end of array
		//For this loop, we need to decide range like (n-i) -1
		//Because i means sorted value, so we need to subtract it from j and we also subtract 1 because we compare j and j + 1 
		//When we have 4 for size, j only needs to go through third value because j =0, 1, 2 and j + 1 = 1, 2, 3 
		//Therefore, we do not have to make j go through fourth value that has index as 3
		for (int j = 0; j < (n - i) - 1; j++) {

			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int main() {

	int arr[5] = { 2, 5, 1, 4, 3 };

	int arrsize = sizeof(arr) / sizeof(arr[0]);

	bubblesort(arr, arrsize);

	for (int i = 0; i < arrsize; i++) {

		std::cout << arr[i] << std::endl;
	}



}
