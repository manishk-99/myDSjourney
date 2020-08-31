#include<iostream>
#include<stack>
using namespace std;

// A stack based efficient method to calculate
//stock span values
void calculateSpan(int price[],int n,int s[]) {
    //create a stack and push index of first element to it
    stack<int>st;
    st.push(0);

    //span value of first element is always 1
    s[0]=1;
    //calculate span values for rest of the elements
    for(int i=1;i<n;i++) {
         // Pop elements from stack while stack is not 
        // empty and top of stack is smaller than 
        // price[i]
        while(!st.empty() && price[st.top()] <= price[i])
        st.pop();

         // If stack becomes empty, then price[i] is 
        // greater than all elements on left of it, 
        // i.e., price[0], price[1], ..price[i-1].  Else 
        // price[i] is greater than elements after 
        // top of stack 
        s[i]=(st.empty()) ? (i+1) : (i-st.top());
        //push this element to stack
        st.push(i);
    }
}

//a utility function to prijt elements of array
void printArray(int arr[], int n) {
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}
//Driver program to test above function
int main() {
    int price[]={10,4,5,90,120,80};
    int n = sizeof(price) / sizeof(price[0]);
    int s[n];
    //fill the span values in array s[]
    calculateSpan(price,n , s);
    //print the calculated span values
    printArray(s,n);
    return 0;
}