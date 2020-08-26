#include<stdio.h>
#include<string.h>

//a utility function to swap 2 numbers
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// a stack based reverse function to reverse a string
void reverse (char str[]) {
    //get size of the string
    int n = strlen(str),i;
    for(i=0;i<n/2;i++)
    swap(&str[i],&str[n-i-1]);
}

//driver programm to check the above functions
int main() {
    char str[] = "Manish Kumar";
    reverse(str);
    printf("Reversed string is %s", str);
    return 0;
}