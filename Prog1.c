#include <stdio.h>

void main() {
	int arr[100],n,i,j,min,temp;
	printf("Enter number of elements: ");
	scanf("%d",  &n);
	printf("Enter %d elements :\n",n);
	
	for (i=0; i < n; i++)
		scanf("%d", &arr[i]);
	
	for (i = 0; i < n - 1; i++) {
		min = i;
		
		for (j = i + 1; j < n; j++) 
			if (arr[j] < arr[min])
				min = j;
	
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;		
	}
	
	printf("Sorted Array: \n");
	
	for (i = 0; i < n; i++) 
	    printf("%d  ", arr[i]);
}