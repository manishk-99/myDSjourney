#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<stdlib.h>

//structure to represent a stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

//function to create a stack of given capacity. It initializes size of stack as 0
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top=-1;
    stack->capacity=capacity;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

//stack is full when top is equal to the last index
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity-1;
}

//stack is empty when top is equal to -1
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

//function to add an item to stack
//it increases top by 1
void push (struct Stack* stack, char item) {
    if(isFull(stack))
    return;
    stack->array[++stack->top] = item;
}

//function to remove an item from the top of the stack. It decreases top by 1
char pop (struct Stack* stack) {
    if(isEmpty(stack))
      return INT_MIN;
     return stack->array[stack->top--];
}

//a stack based function to reverse the string
void reverse(char str[]) {
    //create a stack of capacity equals to the size of the string
    int n = strlen(str);
    struct Stack* stack = createStack(n);

    //push all charcaters of the string to the stack
    int i; 
    for(i=0;i<n;i++) {
        push(stack,str[i]);
    }

    //pop all characters of stack and put them back to sring one by one
    for(i=0;i<n;i++) {
        str[i] = pop(stack);
    }
}
//driver program to test above function
int main()
{
    char str[]= "Manish Kumar";
    reverse(str);
    printf("Reversed string is %s", str);
    return 0;
}