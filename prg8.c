#include <stdio.h>
// Merge two subarrays arr[l..m] and arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;  // Size of left subarray
	int n2 = r - m;      // Size of right subarray
	int L[n1], R[n2];
// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	int i = 0, j = 0, k = l;
// Merge temp arrays back into arr[l..r]
	while (i < n1 && j < n2) {
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while (i < n1)
// Copy remaining elements of L[], if any
		arr[k++] = L[i++];
// Copy remaining elements of R[], if any
	while (j < n2)
		arr[k++] = R[j++];
}
// l is left index, r is right index of the subarray to be sorted
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
// Sort first half
		mergeSort(arr, l, m);
// Sort second half
		mergeSort(arr, m + 1, r);
// Merge the two halves
		merge(arr, l, m, r);
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
	mergeSort(arr, 0, n - 1);
	printf("Sorted array:\n");
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	return 0;
}