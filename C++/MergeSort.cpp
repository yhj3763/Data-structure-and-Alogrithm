//It is implementing MergeSort in C++;
#include <iostream>

//It is function to merge two parts that divides based on recursion into one
//It compares between two parts and store sorted value into temporary array
void MergeTwo(int arr[], int left, int mid, int right)
{
	//Declare values for indexes. 
	//Based on indexex, there are two parts
	//One part from first value to mid
	//Second part from mid +1 to last
	int firstidx = left;
	int secondidx = mid + 1;

	//Make temporary array to store sorted values
	int* sortedarr = new int[right + 1];
	int sortedidx = left;

	//It repats while first index has less than equal to  mid or second index has less than equal to right 
	while (firstidx <= mid && secondidx <= right) {

		//if arr[firstidx] has less than equal to arr[secondidx]
		//Store arr[first] value into sorted array
		//After we store, we need to increase index for sorted array and first index
		//if arr[secondidx] has smaller than arr[firstidx], store it into sorted array
		if (arr[firstidx] <= arr[secondidx]) {
			sortedarr[sortedidx] = arr[firstidx++];
		}
		else {
			sortedarr[sortedidx] = arr[secondidx++];
		}

		sortedidx++;

	}


	//When fistidx hits mid or secondidx hit right, it means all values in other side is bigger than sorted value
	//Therefore, we need to store it to part after we store value by using loop
	//In this case, firstidx becomes bigger than mid, so we need to store other values for second index into sorted array
	if (firstidx > mid) {

		for (int i = secondidx; i <= right; i++, sortedidx++) {
			sortedarr[sortedidx] = arr[i];
		}
	}
	else {
		for (int i = firstidx; i <= mid; i++, sortedidx++) {
			sortedarr[sortedidx] = arr[i];
		}
	}

	//Finally, we need to store sorted array into our original array
	for (int i = left; i <= right; i++) {
		arr[i] = sortedarr[i];
	}

	//Because we finished using sorted array, we need to delete it to prevent memeory leak
	delete[] sortedarr;
	
}


//It is function that include recursion
void MergeSort(int arr[], int left, int right) {

	int mid;

	//It make us to divide array into each value
	//After we divide array into each value, it starts merging and sorting two values
	if (left < right) {

		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwo(arr, left, mid, right);

	}

}


int main() {

	int arr[8] = { 3,2,4,1,7,6,5,8};

	int arrsize = sizeof(arr) / sizeof(arr[0]);


	MergeSort(arr, 0, arrsize - 1);


	for (int i = 0; i < arrsize; i++) {
		std::cout << arr[i] << std::endl;
	}


}



