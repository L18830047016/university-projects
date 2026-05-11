#include <stdio.h>

//折半插入排序
void binaryInsertSort(int *data,int len){
    int low,high,mid;
    int key;

    //从第二个元素开始遍历，将其插入到前面已经排好序的子序列中
    for(int i=1;i<len;i++){
        key=data[i];
        low=0;
        high=i-1;

        //使用折半查找法找出key应该插入的位置（即low最终的位置)
        while(low<=high){
            mid=(low+high)/2;
            if(data[mid]>key){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        //从后往前依次将大于key的元素后移，为key腾出位置
        int j=i-1;
        while(j>=low){
            data[j+1]=data[j];
            j--;
        }

        data[low]=key;
    }
}

int main(int argc, char const *argv[]) {

    int data[] = {47, 35, 60, 95, 77, 15,60, 28};
	int len = sizeof(data) / sizeof(data[0]);

	// 调用折半插入排序
	binaryInsertSort(data, len);

	// 输出排好序的结果
	for(int i = 0; i < len; i++)
	{
		printf("%d ", data[i]);
	}

    return 0;
}

