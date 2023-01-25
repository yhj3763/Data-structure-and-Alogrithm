//It is implementing insertion Sort in C++
#include <iostream>

//It is function for Insertion sort.
//It gets array and size of array as parameters
void Insertionsort(int arr[], int n) {

	//Make two variables to insert values later
	int j;
	int insertdata;


	//For loop outside, it is considred as number of values that are sorted already
	//Unlike other sort, it starts from 1 because we compare sorted value and unsorted value
	//Therefore, we assume first value is already sorted to use it for comparison with unsorted value
	for (int i = 1; i < n; i++) {

		//Initialize value with the value that we want to sort in unsorted values
		insertdata = arr[i];

		//For loop inside, it goes through sorted value and compare these value with unsorted value we want to insert
		//When we want to sort first value in unsorted value, we only need to compare one time
		for (j = i - 1; j >= 0; j--) {

			//If sorted values have bigger numbers than unsorted value, we move sorted value to next place to make new place for unsorted value
			//We need to repeat it until unsorted value find its own position
			if (arr[j] > insertdata) {
				arr[j + 1] = arr[j];
			}
			//If there is bigger value than unsorted value, and there is also smaller value than unsorted value, we need to break the loop
			else{
				break;
			}
		}

		//When we exit the loop, we have one less index than index we want to find
		//When there is no smaller value than unsorted value, it goes through index 0 and it exits loop with -1 that does not satisfy condition
		//Therefore, we need to use j + 1 to make it as index 0 
		//To exit loop, it is usually goes one more position, so we need to use j + 1 to find correct place
		arr[j + 1] = insertdata;
	}


}



int main() {

	int arr[5] = {2, 5, 1, 4, 3};

	int arrsize = sizeof(arr) / sizeof(arr[0]);
	
	int i;
	Insertionsort(arr, arrsize);

	for (i = 0; i < arrsize; i++) {

		std::cout << arr[i] << std::endl;
	}


}
