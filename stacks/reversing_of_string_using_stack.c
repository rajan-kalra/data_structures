#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure representing a Stack
struct Stack {
	int top, capacity;
	char *array;
};

int IsFull (struct Stack *my_stack) {
	return (my_stack->top == (my_stack->capacity - 1));
}

// Function to push element to stack
void Push (struct Stack *my_stack, char item) {
	if (IsFull (my_stack)) {
		// Case : Stack is already full
		printf ("Stack is full!\n");
		return;
	}
	
	// Case : Stack is not full
	my_stack->array[++(my_stack->top)] = item;
}

// Helper function to check if stack is empty
int IsEmpty (struct Stack *my_stack) {
	return (my_stack->top == -1);
}

// Function to pop element from stack
char Pop (struct Stack *my_stack) {
	// Case : Stack is already empty
	if (IsEmpty (my_stack)) {
		return '@';
	}
	
	// Case : Stack is not empty
	return my_stack->array[(my_stack->top)--];
}

// Function to create Stack
struct Stack *CreateStack (int capacity) {
	struct Stack *my_stack = (struct Stack*) malloc (sizeof(struct Stack));
	if (my_stack == NULL) {
		return my_stack;
	}
	
	my_stack->top = -1;
	my_stack->capacity = capacity;
	my_stack->array = (char*) malloc (sizeof(char) * capacity);
	return my_stack;
}

void FreeMemory (struct Stack *my_stack) {
	free (my_stack->array);
	free (my_stack);
	
	printf ("\nDynamic memory freed!\n");
}

int main(void) {
	char str[] = "RajanKalra";
	int i = 0;
	
	printf ("Original string : %s\n", str);
	
	struct Stack *my_stack = CreateStack (15);
	if (my_stack == NULL) {
		printf ("Memory allocation failed!\n");
		return 0;
	}
	
	// Push all string characters to the stack
	while (str[i]) {
		Push (my_stack, str[i++]);
	}
	i = 0;
	
	// Pop all elements from the stack and store them in char array
	while (!IsEmpty(my_stack)) {
		str[i++] = Pop (my_stack);
	}
	str[i] = 0;
	
	printf ("Reversed string : %s\n", str);
	
	FreeMemory (my_stack);
	return 0;
}
