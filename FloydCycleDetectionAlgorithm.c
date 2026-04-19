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

int isCycle(node *start) {
	struct node* slow = start;
	struct node* fast = start;

	while(fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast) return 1;
	}
	return 0;
}

void traverse(node *start, node *end) {
	if(start == NULL) { printf("List is empty!\n"); return; }

	if(!isCycle(start)) {
		while(start != NULL) {
			printf("%d\t", start->val);
			start = start->next;
		}	
	}
	else {
		struct node* rider = start;
		printf("Circular Linked List : ");
		printf("%d\t", rider->val);
		rider = rider->next;
		while(rider != start) {
			printf("%d\t", rider->val);
			rider = rider->next;
		}
	}
}

int main() {
	node *start = NULL, *end = NULL;
	for(int i = 1; i <= 10; i++) {
		linkEnd(&end, createNode(&start, &end, i*10));
	}
	traverse(start, end);
	end->next = start->next->next;
	
	return 0;
}
