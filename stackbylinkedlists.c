#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

//structure to represent a stack
struct stackNode {
    int data;
    struct stackNode* next;
};

struct stackNode*  newNode(int data) {
    struct stackNode* stackNode = (struct stackNode*) malloc(sizeof(struct stackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct stackNode* root) {
    return !root;
}

void push (struct stackNode** root , int data) {
    struct stackNode * stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack \n",data);
}

int pop(struct stackNode** root) {
    if(isEmpty(*root))
    return INT_MIN;
    struct stackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(struct stackNode* root) {
    if(isEmpty(root))
    return INT_MIN;
    return root->data;
}

int main()
{
    struct stackNode* root = NULL;
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    printf("%d popped from stack \n", pop(&root));
    printf("%d is the top element \n", peek(root));
}