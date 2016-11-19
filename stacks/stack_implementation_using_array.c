#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure representing the Stack
struct Stack {
	int top;
	int capacity;
	int *array;
};

// Helper function to check if Stack is empty
int IsEmpty (struct Stack *stack) {
	return (stack->top == -1);
}

// Function to pop an element from the stack
int Pop (struct Stack *stack) {
	
	// Case : Stack is already empty 
	if (IsEmpty (stack)) {
		return INT_MIN;
	}
	
	// Case : Stack is not empty
	return stack->array[(stack->top)--];
}

// Helper function to check if Stack is full
int IsFull (struct Stack *stack) {
	return (stack->top == (stack->capacity - 1));
}

// Function to push an element to the Stack
void Push (struct Stack *stack, int item) {
	
	// Case : Stack is already full
	if (IsFull (stack)) {
		printf ("Stack is full, could not insert %d!\n", item);
		return;
	}
	
	// Case : Stack is not full
	stack->array[++(stack->top)] = item;
	printf("%d pushed to stack!\n",item);
}

int Peek (struct Stack *stack) {

	// Case : Stack is empty
	if (IsEmpty (stack)) {
		return INT_MIN;
	}
	
	// Case : Stack is not emtpy
	return stack->array[stack->top];
}

// Function to create an empty Stack 
struct Stack *CreateStack (int capacity) {
	struct Stack *my_stack = (struct Stack*) malloc (sizeof(struct Stack));
	
	// Case : Dynamic memory allocation not successful
	if (my_stack == NULL) {
		return my_stack;
	}
	
	// Case : Dynamic memory allocation successful
	my_stack->top = -1;
	my_stack->capacity = capacity;
	my_stack->array = (int*) malloc (sizeof(int) * capacity);
	return my_stack;
}

void FreeMemory (struct Stack *stack) {
	free (stack->array);
	free (stack);
	
	printf ("\nDynamic memory freed successfully!");
}

int main() {
	struct Stack *my_stack = NULL;
	my_stack = CreateStack (5);
	
	if (my_stack == NULL) {
		printf ("Memory allocation unsuccessful!\n");
		return 0;
	}
	
	// Testing functions
	Push (my_stack, 1);
	Push (my_stack, 2);
	printf ("Current top element : %d\n", Peek (my_stack));
	Push (my_stack, 3);
	Push (my_stack, 4);
	printf ("Current top element : %d\n", Peek (my_stack));
	Push (my_stack, 5);
	Push (my_stack, 6);
	Push (my_stack, 7);
	printf ("%d popped from stack!\n", Pop (my_stack));
	printf ("%d popped from stack!\n", Pop (my_stack));
	printf ("%d popped from stack!\n", Pop (my_stack));
	printf ("%d popped from stack!\n", Pop (my_stack));
	printf ("%d popped from stack!\n", Pop (my_stack));
	printf ("%d popped from stack!\n", Pop (my_stack));
	
	FreeMemory (my_stack);
	return 0;
}
