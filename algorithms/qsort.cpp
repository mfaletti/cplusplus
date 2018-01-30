#include <iostream>
using namespace std;

void print(int* A, int n) {
	for (int i = 0;i<n;i++)
		cout<< A[i] << "";

	std::cout<<"\n";
}

void quicksort(int* arr, int low, int high) {
	int i, j, temp, pivot;

	if (low < high) {
		pivot = low; // select a pivot
		i = low;
		j = high;

		while (i < j) {
			//increment until you get a number greater than the pivot element
			while (arr[i] <= arr[pivot] && i <= high)
				i++;

			// decrement until you get a number less than the pivot element
			while (arr[j] > arr[pivot] && j >= low)
				j--;

			// if i < j, swap the elements in locations i & j
			if (i < j) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		// when i >= j, it means the j-th position is the correct position of the pivot element,
		// so swap the pivot element with the element in the j-th position
		temp = arr[j];
		arr[j] = arr[pivot];
		arr[pivot] = temp;

		//repeat quicksort for the two sub-arrays, one to the left of j
		// and the one to the right of j
		quicksort(arr, 0, j-1);
		quicksort(arr, j+1, high);
	}
}

int main(void) {
	int a[] = {9,8,7,6,4,5,3,2,1,8}, n = sizeof(a)/sizeof(a[0]);

	cout<<"list before sort: ";
	print(a, n);
	quicksort(a, 0, n-1);
	cout<<"list after sort: ";
	print(a, n);

	return 0;
}