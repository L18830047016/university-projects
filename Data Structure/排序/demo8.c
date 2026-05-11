#include <stdio.h>

//将数组划分为左右两个部分，返回基准值的最终位置
int partition(int *data,int low,int high){
    //选择最左侧元素作为基准值
    int pivot=data[low];

    //当low与high没有相遇时，继续循环
    while(low<high){
        //从右向左寻找第一个比pivot小的数
        while(low<high&&data[high]>=pivot){
            high--;
        }
        //将较小的值填入左侧“坑”中
        data[low]=data[high];

        //从左向右寻找第一个比pivot大的数
        while(low<high&&data[low]<=pivot){
            low++;
        }
        //将较大的值填入右侧的坑中
        data[high]=data[low];
    }

    //当low==high时，即找到pivot应该放置的位置
    data[low]=pivot;
    return low;//返回pivot的最终位置
}

//快速排序主函数，采用递归方式
void quickSort(int* data,int low,int high){
    int pivot;
    if(low<high){
        //对当前区间进行划分，并获取pivot的位置
        pivot=partition(data,low,high);

        //对pivot左侧子数组递归进行快速排序
        quickSort(data,low,pivot-1);

         // 对 pivot 右侧子数组递归进行快速排序
        quickSort(data, pivot + 1, high);
    }
}
int main(int argc, char const *argv[]) {

    int data[] = {47, 35, 60, 95, 77, 15, 28};
    int len = sizeof(data) / sizeof(data[0]);

    // 执行快速排序
    quickSort(data, 0, len-1);

    // 输出排序后的结果
    for(int i = 0; i < len; i++)
    {
        printf("%d ", data[i]);
    }

    return 0;
}