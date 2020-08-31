#include<stdio.h>
//fills array s[] with span values 
void calculateSpan (int price[],int n,int s[]) {
    //span value of first day is always 1
    s[0]=1;
    //calculate span value of remaining days by linearly checking previous days
    for(int i=1;i<n;i++) {
        s[i]=1; //Initialize span value
        //Traverse left while the next element on left is smaller than price[i]
        for(int j=i-1;(j>=0) && (price[i]>=price[j]); j--)
        s[i]++;
    }
}

//A utility function to print elements of an array
void printArray(int arr[],int n) {
    for(int i=0;i<n;i++)
    printf("%d ", arr[i]);
}

//driver program to test above function
int main() 
{ 
    int price[] = { 10, 4, 5, 90, 120, 80 }; 
    int n = sizeof(price) / sizeof(price[0]); 
    int s[n]; 
  
    // Fill the span values in array S[] 
    calculateSpan(price, n, s); 
  
    // print the calculated span values 
    printArray(s, n); 
  
    return 0; 
} 