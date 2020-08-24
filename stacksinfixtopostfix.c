#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

//stack type
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
    stack->array = (int*) malloc(stack->capacity* sizeof(int));
    if(!stack-> array)
    return NULL;
    return stack;
}

int isEmpty (struct Stack* stack) {
    return stack->top == -1;
}
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}
char pop(struct Stack* stack) {
    if(!isEmpty(stack))
    return stack->array[stack->top--];
    return '$';
}

void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}
//a utility function to check if the given character is operand
int isOperand(char ch) {
    return (ch>= 'a' && ch<= 'z') || (ch>='A' && ch<= 'Z');
}

//a utility function to return precedence of a given operator
//higher returned value means higher precedence
int prec(char ch) {
    switch(ch) {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
    }
    return -1;
} 

//the main function that coverts the given infix expression
//to postfix expression
int infixToPostfix(char* exp) {
    int i,k;
    //create a stack of capacity equal to the expression size
    struct Stack* stack = createStack(strlen(exp));
    if(!stack)//see if stack was created succesfully
    return -1;
    for(i=0 , k=-1 ; exp[i] ; ++i) {
        //if the scanned character is an operator, add it to output
        if(isOperand(exp[i])) 
        exp[++k]=exp[i];

        //if the scanned charater is an '(', push it to the stack
        else if(exp[i]=='(')
        push(stack, exp[i]);

        //if the stack character is an ')',pop and output from the stack
        //until and '(' is encountered
        else if(exp[i] ==')') {
            while(!isEmpty(stack) && peek(stack)!='(')
            exp[++k]= pop(stack);
            if(!isEmpty(stack) && peek(stack)!='(')
            return -1; //invalid expression
            else
            pop(stack);
        }
        else  // an operator is encountered
        {
            while(!isEmpty(stack) && prec(exp[i]) <= prec(peek(stack)))
            exp[++k] = pop(stack);
            push(stack, exp[i]);
        }
}
while(!isEmpty(stack))
exp[++k] = pop(stack);

exp[++k] = '\0';
printf("%s", exp);
}

int main() 
{ 
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i"; 
    infixToPostfix(exp); 
    return 0; 
}