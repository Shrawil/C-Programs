#include <stdio.h>
#include <stdlib.h>

void init(int bucket[][6]) {
	for(int r = 0; r < 10; r++) {
		for(int c = 0; c < 6; c++) {
			if(c == 5) bucket[r][c] = -1;
			else bucket[r][c] = 0;
		}
	}
}

void printarr(int bucket[][6], int arr[]) {
	printf("\nArr[] = ");
	for(int i = 0; i < 5; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n\n");
	for(int r = 0; r < 10; r++) {
		for(int c = 0; c < 6; c++) {
			printf("%d\t", bucket[r][c]);
		}
		printf("\n");
	}
}


void radixSort(int arr[]) {

}

int main() {

	int arr[5] = {13, 76, 55, 34, 76}; //Array to be sorted
	int bucket[10][6]; //10 rows for all digits 0-9 and 6 columns for all elements and back.
	init(bucket);
	printarr(bucket, arr);
	radixSort(arr)
	return 0;
	
}