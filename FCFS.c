#include <stdio.h>

typedef struct proc {
	int pid, at, bt, ct, tat, wt;
	int rt;
} proc; 

void printArr(proc p[], float avgTat, float avgWt, int n) {
	printf("\n\nP\tAT\tBT\tCT\tTAT\tWT");
	for(int i = 0; i < n; i++) {
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",
			p[i].pid, p[i].at, p[i].bt,
			p[i].ct, p[i].tat, p[i].wt);
	}
	printf("\nAvg TAT = %.2f\nAvg WT = %.2f\n", avgTat, avgWt);
}

void calcAvg(proc p[], float *tat, float *wt, int size) {
	int totalTAT = 0;
	int totalWT = 0;
	for(int i = 0; i < size; i++) {
		totalTAT += p[i].tat;
		totalWT += p[i].wt;
	}
	*tat = (float)totalTAT/size;
	*wt = (float)totalWT/size;
}

int main() {
	proc p[5] = {
		{1, 0, 4, 0, 0, 0, 4}, 
		{2, 1, 6, 0, 0, 0, 6}, 
		{3, 2, 1, 0, 0, 0, 1}, 
		{4, 3, 7, 0, 0, 0, 7}, 
		{5, 4, 4, 0, 0, 0, 4}
	};
	int size = 5;
	// Sorting by arrival time.

	for(int i = 0; i < size - 1; i++) {
		for(int j = 0; j < size - i - 1; j++) {
			if(p[j].at > p[j+1].at) {
				proc temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}

	float avgTat = 0, avgWt = 0;
	printArr(p, avgTat, avgWt, size);
	int current_time = 0;
	for(int i = 0; i < size; i++) {

	    if(current_time < p[i].at)
	        current_time = p[i].at;

	    p[i].ct = current_time + p[i].bt;
	    current_time = p[i].ct;

	    p[i].tat = p[i].ct - p[i].at;
	    p[i].wt  = p[i].tat - p[i].bt;
	}
	calcAvg(p, &avgTat, &avgWt, size);
	printArr(p, avgTat, avgWt, size);
	return 0;
}