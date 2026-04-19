#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val; 
	struct node *next;
} node;

node* createNode(node **start, node **end, int val) {
	node *nnptr = (node *)malloc(sizeof(node));
	nnptr->val = val;
	nnptr->next = NULL;
	if(*start == NULL) *start = *end = nnptr;
	return nnptr; 
}

void linkEnd(node **end, node *nnptr) {
	(*end)->next = nnptr;
	*end = nnptr;
}

void traverse(node *start) {
	while(start != NULL) {
		printf("%d\t", start->val);
		start = start->next;
	}
}

int main() {
	node *start = NULL, *end = NULL;
	for(int i = 1; i <= 10; i++) {
		linkEnd(&end, createNode(&start, &end, i*10));
	}
	traverse(start);
	end->next = start->next->next->next;
	return 0;
}
