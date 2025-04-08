#include<iostream>
using namespace std;

int SumRecursive(int a[], int n){
    if(n<=0)
    return 0;
    return (a[n-1] + SumRecursive(a, n-1));
}

int SumIterative(int a[], int n){
    int Sum=0;
    for(int i=0; i<n; i++){
        Sum+=a[i];
    }
    return Sum;
}

int main()
{
    int n;
    cout<<"\n\nEnter number of elements of integer array: ";
    cin>>n;
    int intArr[n];

    cout<<"Enter elements in array: \n";
    for(int i=0; i<n; i++){
        cin>>intArr[i];
    }

    cout<<"\nSum of all elements by recursive function: "<<SumRecursive(intArr, n);
    cout<<"\nSum of all elements by iterative function: "<<SumIterative(intArr, n);

    return 0;
}

