#include <stdio.h>

// 交换数组中下标为 m 和 n 的两个元素
void swap(int* data, int m, int n)
{
	int temp = data[m];
	data[m] = data[n];
	data[n] = temp;
}

//简单选择排序函数
void selectSort(int* data,int len){
    int min;
    //外层循环：控制每一轮的起始位置
    for(int i=0;i<len;i++){
        //假设当前位置i是最小值
        min=i;
        //内层循环：从当前位置i向后寻找最小值的位置
        for(int j=i;j<len;j++){
            //如果发现比当前最小值还小的元素，更新最小值的位置
            if(data[min]>data[j]){
                min=j;
            }
        }
        if(i!=min){
            swap(data,i,min);
        }
    }
}
int main(int argc, char const *argv[]) {

    	// 初始化数组
	int data[] = {47, 35, 60, 95, 77, 15, 28};
	// 计算数组长度
	int len = sizeof(data) / sizeof(data[0]);
	// 执行选择排序
	selectSort(data, len);
	// 输出排序后的结果
	for(int i = 0; i < len; i++)
	{
		printf("%d ", data[i]);
	}

    return 0;
}