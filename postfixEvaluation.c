#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Stack type
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

//stack Operations
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    if(!stack)
    return NULL;
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack-> capacity * sizeof(int));
    if(!stack->array)
    return NULL;
    return stack;
}

//4 utility functions
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}
void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}
char pop( struct Stack* stack) {
    if(!isEmpty(stack))
    return stack->array[stack->top--];
    return '$';
}

//The main function that returns value of a given POSTFIX EXPRESSION.

int evaluatePostfix (char* exp) {
    //Create a STACK of capacity equals to the expression size
    struct Stack* stack = createStack(strlen(exp));
    int i;
     //See if STACK was created successfully
     if(!stack)
     return -1;
      //Scan all characters one by one
      for(i=0;exp[i];++i) {
           //If the scanned characters is an operand or number
            //Push it to the stack
            if(isdigit(exp[i]))
            push(stack,exp[i]-'0');

            //If the scanned character is an operator , POP 2 elements from the STACK and apply the operator
            else {
                int val1 = pop(stack);
                int val2 = pop(stack);
                switch(exp[i]) {
                    case '+': push(stack, val2 + val1); break;
                    case '-': push(stack, val2 - val1); break;
                    case '*': push(stack, val2 * val1); break;
                    case '/': push(stack, val2 / val1); break;
                }
            }
        }
     return pop(stack);
}

//Driver PROGRAM
int main() 
{
    char exp[] = "231*+9-";
    printf("Value of %s is %d",  exp,evaluatePostfix(exp));
    return 0;
}