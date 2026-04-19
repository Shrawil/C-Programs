#include <stdio.h>

void printarr(int arr[], int k, int min, int temp, int p) {
	int i;
	for(i = 0; i < 5; i++) {
		if(i == p) printf("P\t");
		else printf("\t");
	}
	printf("\n");
	for(i = 0; i < 5; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
	for(i = 0; i < 5; i++) {
		if(i == k) printf("K\t");
		else printf("\t");
	}
	
	printf("\nmin = %d | temp = %d\n", arr[min], temp);
}

void main() {
	/* 
	1. We start with 0 index (k) and assume the element (min) the smallest.
	2. As we iterate if another element is smaller than min we save it as min.
	3. At the end of that iteration we swap the min value with element at kth index.
	4. Increment k and repeat step 1 to 3 till the array is sorted.
	*/
	int arr[] = {4,3,7,1,8};
	int temp;
	for(int k = 0; k < 5; k++) {
		int min = k;
		for(int p = k + 1; p < 5; p++) {
			if(arr[p] < arr[min]) min = p;
			printarr(arr, k, min, temp, p);
		}
		if(min != k) {
			int temp = arr[k];
			arr[k] = arr[min];
			arr[min] = temp;
		}
	}

}