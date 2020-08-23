#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

//Structure to represent a stack
struct stack {
    int top;
    unsigned capacity;
    int* array;
};

//function to create a stack of given capacity .
//it initializes the sizes of stack as 0

struct stack* createStack(unsigned capacity){
    struct stack* stack = (struct stack*) malloc(sizeof(struct stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

//stack if full when top is equal to the last index
int isfull (struct stack* stack){
    return stack->top == stack->capacity-1;
}

//stack is empty when top is equal to -1
int isempty (struct stack* stack) {
    return stack->top == -1;
}

//function to add an item to stack.
//it increases top by 1
void push (struct stack* stack, int item) {
    if(isfull(stack))
    return;
    stack->array[++stack->top] = item;
    printf("%d is pushed to the stack \n", item);
}

//function to remove an item from the stack
//it decreases top by 1
int pop(struct stack* stack) {
    if(isempty(stack))
    return INT_MIN;
    return stack->array[stack->top--];
}

//function to get top item from the stack
int peak(struct stack* stack) {
    if(isempty(stack))
    return INT_MIN;
    return stack->array[stack->top];
}

//driver programme to test above functions
int main() 
{
    struct stack* stack = createStack(100);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("%d is popped \n", pop(stack));
    printf("%d is top item \n", peak(stack));
}