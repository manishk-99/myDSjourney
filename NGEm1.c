#include<stdio.h>
//prints element and NGE pair of all elements of arr[] of size n
void printNGE(int arr[], int n) {
    int next;
    for(int i=0;i<n;i++) {
        next=-1;
        for(int j=i+1;j<n;j++) {
            if(arr[i]<arr[j]) {
                next=arr[j];
                break;
            }
        }
        printf("%d -- %d\n", arr[i], next);
    }
}

int main() {
    int arr[]={13,7,6,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    printNGE(arr,n);
    return 0;
}