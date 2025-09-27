#include <stdio.h>
struct Result {
	int min;
	int max;
};
struct Result findMinMax(int arr[], int low, int high) {
	struct Result res, left, right;
	int mid;
// If one element
	if (low == high) {
		res.min = res.max = arr[low];
		return res;
	}
// If two elements
	if (high == low + 1) {
		if (arr[low] < arr[high]) {
			res.min = arr[low];
			res.max = arr[high];
		} else {
		}
		res.min = arr[high];
		res.max = arr[low];
		return res;
	}
// If more than two elements
	mid = (low + high) / 2;
	left = findMinMax(arr, low, mid);
	right = findMinMax(arr, mid + 1, high);
	res.min = (left.min < right.min) ? left.min : right.min;
	res.max = (left.max > right.max) ? left.max : right.max;
	return res;
}
int main() {
	int arr[100], n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	printf("Enter array elements:\n");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	struct Result result = findMinMax(arr, 0, n - 1);
	printf("Minimum element: %d\n", result.min);
	printf("Maximum element: %d\n", result.max);
	return 0;
}
