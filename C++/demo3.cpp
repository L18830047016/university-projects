#include <iostream>
#include "demo3.h"
using namespace std;

//º¯Êý¶¨Òå
void printArr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void printArr1(int arr[]){
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}