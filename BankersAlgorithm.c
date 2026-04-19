#include <stdio.h>

// Banker's Algorithm

struct proc {
	int pid;
	// A B C
	int alloc[3];
	int max[3];
	int need[3];
};

void printArr(struct proc p[], int size) {
	printf("\nP.ID\tA  B  C \t A  B  C \t A  B  C");
	printf("\n    \t Alloc  \t Max Need\t Res Need ");
	for(int i = 0; i < size; i++) {
		printf("\n%d   \t%d  %d  %d \t %d  %d  %d \t %d  %d  %d", p[i].pid, p[i].alloc[0], p[i].alloc[1], p[i].alloc[2], p[i].max[0], p[i].max[1], p[i].max[2], p[i].need[0], p[i].need[1], p[i].need[2]);
	}
}

void main() {
	int ava[3] = {3,3,2}, total[3] = {10, 5, 7};
	int size = 5;
 	struct proc p[5] = {
		{1, {0,1,0}, {7,5,3}, {0}},
		{2, {2,0,0}, {3,2,2}, {0}},
		{3, {3,0,2}, {9,0,2}, {0}},
		{4, {2,1,1}, {4,2,2}, {0}},
		{5, {0,0,2}, {5,3,3}, {0}}
	};
	for(int i = 0; i < size; i++) {
	    for(int j = 0; j < 3; j++) {
	        p[i].need[j] = p[i].max[j] - p[i].alloc[j];
	    }
	}
	
	printArr(p, size);
	printf("\n");

	int finished[5] = {0};
	int found;
	int completed = 0;
	while(completed < 5) {
		found = 0; // No process found to be executed
		for(int i = 0; i < size; i++) { // Runs until all process are executed
			int freeRes = 1;
			for(int j = 0; j < 3; j++) {
				if(p[i].need[j] > ava[j]) {
					freeRes = 0;
					break;
				}	
			}
			if(freeRes && !finished[i]) {
				for(int j = 0; j < 3; j++) {
					ava[j] += p[i].alloc[j]; // Add allocated res to available res.
				}
				printf("\nExecuted Program : %d", p[i].pid);
				finished[i] = 1;
				completed += 1;
				found = 1;
			}
		}
		if(!found) { // To check if no process executed after 5 iterations.
			printf("\nUnsafe state!"); 
			break;			
		}
	}
	return;
}
