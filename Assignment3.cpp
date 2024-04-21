#include<iostream>
#include<omp.h>
using namespace std;

int minval(int arr[],int n){
    int minval=arr[0];
    #pragma omp parallel for reduction(min : minval)
    for(int i=0;i<n;i++){
        if(arr[i]<minval) minval=arr[i];
    }
    return minval;
}

int maxval(int arr[],int n){
    int maxval=arr[0];
    #pragma omp parallel for reduction(max:maxval)
    for(int i=0;i<n;i++){
        if(arr[i]>maxval) maxval=arr[i];
    }
    return maxval;
}

int sum(int arr[],int n){
    int sum=0;
    #pragma omp parallel for reduction(+:sum)
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int average(int arr[],int n){
    return (double)sum(arr,n)/n;
}
int main(){
    int n=5;
    int arr[]={1,2,3,4,5};
    cout<<"The Minimum Value Is: "<<minval(arr,n)<<endl;
    cout<<"The Maximum Value Is: "<<maxval(arr,n)<<endl;
    cout<<"The Summation Is: "<<sum(arr,n)<<endl;
    cout<<"The Average Is: "<<average(arr,n)<<endl;
}