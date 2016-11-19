#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct DualStack {
	int top1, top2, capacity;
	int *array;
};

// Function to create Dual Stack
struct DualStack *CreateDualStack (int capacity) {
	struct DualStack *my_dstack = (struct DualStack*) malloc (sizeof(struct DualStack));
	// Case : Dynamic memory allocation failed
	if (my_dstack == NULL) {
		return my_dstack;
	}
	
	my_dstack->array = (int*) malloc (sizeof(int) * capacity);
	// Case : Dynamic memory allocation failed
	if (my_dstack->array == NULL) {
		return my_dstack;
	}
	
	my_dstack->top1 = -1;
	my_dstack->top2 = capacity;
	my_dstack->capacity = capacity;
	
	return my_dstack;
}

// Function to push element to stack 1
void Push1 (struct DualStack *my_dstack, int item) {
	// Case : Stack 1 is not full
	if ((my_dstack->top1 + 1) < my_dstack->top2) {
		my_dstack->array[++(my_dstack->top1)] = item;
		printf ("%d pushed to stack 1\n", item);
		return;
	}
	
	// Case : Stack 1 is full
	printf ("Stack 1 is full, could not insert %d!\n", item);
}

// Function to push element to stack 2
void Push2 (struct DualStack *my_dstack, int item) {
	// Case : Stack 2 is not full
	if ((my_dstack->top2 - 1) > my_dstack->top1) {
		my_dstack->array[--(my_dstack->top2)] = item;
		printf ("%d pushed to stack 2\n", item);
		return;
	}
	
	// Case : Stack 1 is full
	printf ("Stack 2 is full, could not insert %d!\n", item);
}

// Function to pop element from Stack 1
int Pop1 (struct DualStack *my_dstack) {
	// Case : Stack 1 is already empty
	if (my_dstack->top1 == -1) {
		return INT_MIN;
	}
	
	// Case : Stack 1 is not empty
	return my_dstack->array[(my_dstack->top1)--];
}

// Function to pop element from Stack 2
int Pop2 (struct DualStack *my_dstack) {
	// Case : Stack 2 is already empty
	if (my_dstack->top1 == my_dstack->capacity) {
		return INT_MIN;
	}
	
	// Case : Stack 1 is not empty
	return my_dstack->array[(my_dstack->top2)++];
}


int main () {
	struct DualStack *my_dstack = CreateDualStack (10);
	Push1 (my_dstack, 1);
	Push1 (my_dstack, 2);
	Push1 (my_dstack, 3);
	Push1 (my_dstack, 14);
	Push1 (my_dstack, 53);
	Push1 (my_dstack, 21);
	Push1 (my_dstack, 15);
	Push1 (my_dstack, 16);
	Push1 (my_dstack, 17);
	Push1 (my_dstack, 10);
	Push1 (my_dstack, 11);
	Push2 (my_dstack, 111);
	printf ("%d popped from stack 1!\n", Pop1 (my_dstack));
	Push2 (my_dstack, 111);
	return 0;
}