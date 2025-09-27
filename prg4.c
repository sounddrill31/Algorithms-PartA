#include <stdio.h>
int main() {
	int n, W;
	float weight[100], value[100], ratio[100], total = 0;
	printf("Enter number of items: ");
	scanf("%d", &n);
	printf("Enter knapsack capacity: ");
	scanf("%d", &W);

	for (int i = 0; i < n; i++) {
		printf("Enter weight and value of item %d: ", i + 1);
		scanf("%f %f", &weight[i], &value[i]);
		ratio[i] = value[i] / weight[i];
	}

	// Greedy selection based on ratio
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ratio[i] < ratio[j]) {
				float tmp;

				tmp = ratio[i];
				ratio[i] = ratio[j];
				ratio[j] = tmp;
				tmp = weight[i];
				weight[i] = weight[j];
				weight[j] = tmp;
				tmp = value[i];
				value[i] = value[j];
				value[j] = tmp;
			}
		}
	}

	for (int i = 0; i < n && W > 0; i++) {
		if (weight[i] <= W) {
			total += value[i];
			W -= weight[i];
		} else {
			total += ratio[i] * W;
			break;
		}
	}

	printf("Maximum value: %.2f\n", total);
	return 0;
}