#include<stdio.h>

int main() {
	int arr[] = {5,2,6,1,8,9,6};
	int i, flag = 0;
	int size = sizeof(arr)/sizeof(arr[0]);
	for(i = 0; i < size; i++) printf("%d\t", arr[i]);
	printf("\n");
	for(int pass = 0; pass < size - 1; pass++) {
	    flag = 0;
	    for(int p = 0; p < size - 1 - pass; p++) {
	        if(arr[p] > arr[p+1]) {
	            flag = 1;
	            int temp = arr[p];
	            arr[p] = arr[p+1];
	            arr[p+1] = temp;
	        }
	    }
	    if(flag == 0) {
	        break;
	    }
	}
	for(i = 0; i < size; i++) printf("%d\t", arr[i]);
	return 0;
}