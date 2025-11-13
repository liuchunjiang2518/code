//实验十
//排序算法设计
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//打印数组
void printArr(int* arr,int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//直接插入排序
void insertSort(int* arr,int len)
{
    int i,j,temp;
    for (i=1;i<len;i++)
    {          
        if (arr[i]<arr[i-1])
        { 
            temp=arr[i];           
            for (j=i-1;j>=0&&arr[j]>temp;j--)
            {
                arr[j+1]=arr[j];
            }
            arr[j+1] = temp;
        }
    }
}

//折半插入排序
void binaryInsertSort(int* arr,int len)
{
    int i,j,low,high,mid,temp;
    for(i=1;i<len;i++)
    {
        temp=arr[i];
        low=0;
        high=i-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(arr[mid]>temp)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        for(j=i-1;j>=high+1;j--)
        {
            arr[j+1]=arr[j];
        }
        arr[high+1]=temp;
    }
}

//希尔排序
void shellSort(int* arr,int len)
{
    int gap,i,j,temp;
    for (gap=len/2;gap>0;gap/=2)
    {
        for(i=gap;i<len;i++)
        {
            temp=arr[i];
            for(j=i-gap;j>=0&&arr[j]>temp;j-=gap)
            {
                arr[j+gap]=arr[j];
            }
            arr[j+gap]=temp;
        }
    }
}

//冒泡排序
void bubbleSort(int* arr,int len)
{
    int i,j,temp;
    int flag;
    for(i=0;i<len-1;i++)
    {
        flag=0;
        for(j=0;j<len-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0) 
        {
            break;
        }
    }
}

//快速排序分区函数
int partition(int* arr, int low, int high)
{
    int pivot=arr[low]; 
    while(low<high)
    {
        while(low<high&&arr[high]>=pivot)
        {
            high--;
        }
        arr[low]=arr[high];
        while(low<high&&arr[low]<=pivot)
        {
            low++;
        }
        arr[high]=arr[low];
    }
    arr[low]=pivot;
    return low;
}

//快速排序
void quickSort(int* arr,int low,int high)
{
    if(low<high)
    {
        int pos=partition(arr,low,high);
        quickSort(arr,low,pos-1);        
        quickSort(arr,pos+1,high);       
    }
}

int main()
{
    int arr[]={64,34,25,12,22,11,90};
    int len=sizeof(arr)/sizeof(arr[0]);
    int arr_copy[100];

    //测试直接插入排序
    memcpy(arr_copy,arr,len*sizeof(int));
    printf("原始数组:");
    printArr(arr_copy,len);
    insertSort(arr_copy,len);
    printf("直接插入排序:");
    printArr(arr_copy, len);

    //测试折半插入排序
    memcpy(arr_copy,arr,len*sizeof(int));
    binaryInsertSort(arr_copy,len);
    printf("折半插入排序:");
    printArr(arr_copy,len);

    //测试希尔排序
    memcpy(arr_copy,arr,len*sizeof(int));
    shellSort(arr_copy, len);
    printf("希尔排序:");
    printArr(arr_copy,len);

    //测试冒泡排序
    memcpy(arr_copy,arr,len*sizeof(int));
    bubbleSort(arr_copy,len);
    printf("冒泡排序:");
    printArr(arr_copy,len);

    //测试快速排序
    memcpy(arr_copy,arr,len*sizeof(int));
    quickSort(arr_copy,0,len-1);
    printf("快速排序:");
    printArr(arr_copy,len);

    return 0;
}