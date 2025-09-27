#include <stdio.h>
// Function to swap two elements
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
	int pivot = arr[high];  // pivot element
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
		swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return i + 1;
}
// Quick Sort function (divide and conquer)
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		// Recursively sort elements before and after partition
		quickSort(arr, pi + 1, high);
		quickSort(arr, low, pi - 1);
	}
}

int main() {
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	int arr[n];
	printf("Enter %d elements:\n", n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	quickSort(arr, 0, n - 1);
	printf("Sorted array:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}