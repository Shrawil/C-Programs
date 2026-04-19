#include <stdio.h>

void printArr(int arr[], int left, int right, int elem, int size) {
	int i = 0, mid = (left + right)/2;
	printf("\n");
	// To show MID
	for(i = 0; i < size; i++) {
		if(i == mid) printf("MID\t");
		else printf("\t");
	}
	printf("\n");
	// To show index
	for(i = 0; i < size; i++) {
		printf("%d\t", i);
	}
	printf("\n");
	// To show LEFT
	for(i = 0; i < size; i++) {
		if(i == left) printf("LEFT\t");
		else printf("\t");
	}
	printf("\n");
	// To show array element
	for(i = 0; i < size; i++) {
		if(arr[i] == elem) printf("[%d]\t", arr[i]);
		else printf("%d\t", arr[i]);
	}
	printf("\n");
	// To show RIGHT
	for(i = 0; i < size; i++) {
		if(i == right) printf("RIGHT\t");
		else printf("\t");
	}
}

void main() {
	int arr[] = {12, 28, 34, 55, 58, 87, 90, 94, 101, 180};
	int elem = 101, left = 0, right = 9, size = 10;
	int found = 0;
	printArr(arr, left, right, elem, size);
	int mid;

	while(left <= right) {
		mid = (left + right)/2;
		if(arr[mid] == elem) {
			found = 1;
			break;
		}
		else if(arr[mid] > elem) {
			// Our element can be on the left side of mid.
			right = mid - 1;
		}
		else {
			// Our element can be on the right side of mid.
			left = mid + 1;
		}
		printArr(arr, left, right, elem, size);
	}
	if(found) printf("\nElement %d found at index %d!", elem, mid);
	else printf("\nElement %d could not be found!", elem);
}