#include <stdio.h>
//折半查找函数(需保证查找表中的元素是顺序排列的)
int binary_search(int *data,int len,int value){
    int low=0;
    int high=len-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(value>data[mid]){
             low=mid+1;
        }
        else if(value<data[mid]){
            high=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(int argc, char const *argv[]) {

    int arr[] = {2, 13, 22, 38, 46, 58, 66, 77, 85, 98}; //查找表
	int len = sizeof(arr) / sizeof(arr[0]); //数组长度
	int pos = binary_search(arr, len, 66); //调用函数查找66
	printf("%d\n", pos+1);

    return 0;
}