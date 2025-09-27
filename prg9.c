#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int arr[], int l, int m, int r) {
	int i = l, j = m + 1, k = 0;
	int *temp = (int *)malloc((r - l + 1) * sizeof(int));
	while (i <= m && j <= r) {
		if (arr[i] <= arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}
	while (i <= m) temp[k++] = arr[i++];
		while (j <= r) temp[k++] = arr[j++];
			for (i = l, k = 0; i <= r; i++, k++)
				arr[i] = temp[k];
	free(temp);
}
void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
int main() {
	int testSizes[] = {6000, 10000, 20000, 40000, 80000, 160000};
	int numTests = sizeof(testSizes) / sizeof(testSizes[0]);
	printf("n\tTime (seconds)\n");
	printf("--------------------\n");
	for (int t = 0; t < numTests; t++) {
		int n = testSizes[t];
		int *arr = (int *)malloc(n * sizeof(int));
		
		// Generate random array
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			arr[i] = rand();
		}
		
		// Measure time
		clock_t start = clock();
		mergeSort(arr, 0, n - 1);

		clock_t end = clock();

		double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("%d\t%.5f\n", n, timeTaken);

		free(arr);
	}

	return 0;
}