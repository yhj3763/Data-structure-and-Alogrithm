#include <iostream>

using namespace std;

int binary_search(int arr[], int target, int length)
{
	int first = 0;
	int last = length - 1;
	int mid = 0;
	int count = 0;

	while (first <= last)
	{
		mid = (first + last) / 2;

		if (arr[mid] == target)
		{
			cout << count << endl;
			return mid;
		}

		if (arr[mid] > target)
		{
			last = mid - 1;
		}
		else
		{
			first = mid + 1;

		}

		count++;
	}

	return -1;
}

int main()
{
	int arr[] = { 1,2,3,7,9,12,21,23,27 };

	int target = 21;

	int length = sizeof(arr) / sizeof(arr[0]);

	int result = binary_search(arr, target, length);

	cout << result << endl;




}
