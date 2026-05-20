#include <iostream>
using namespace std;

void printArr(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printArr(double *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void printArr(char *arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr1[5]={1,2,3,4,5};
    double arr2[5]={1.1,2.2,3.3,4.4,5.5};
    char arr3[5]={'a','b','c','d','e'};

    printArr(arr1,5);
    printArr(arr2,5);
    printArr(arr3,5);

    return 0;
}