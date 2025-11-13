//堆排序
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArr(int* arr,int len)
{
    for(int i=0;i<len;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void heapAdjust(int* arr,int i,int len)
{
    int temp=arr[i];
    for(int j=2*i+1;j<len;j=2*j+1)
    { 
        if(j+1<len&&arr[j]<arr[j+1])
        {
            j++;
        }
        if(arr[j]>temp)
        { 
            arr[i]=arr[j];
            i=j;
        }
        else
        {
            break;
        }
    }
    arr[i]=temp;            
}

void heapSort(int* arr,int len)
{
    for(int i=len/2-1;i>=0;i--)
    {
        heapAdjust(arr,i,len);
    }
    for(int i=len-1;i>0;i--)
    {
        int temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapAdjust(arr,0,i);
    }
}

int main()
{
    int arr[]={5,3,8,5,2,9,5,1};
    int len=sizeof(arr)/sizeof(arr[0]);
    printf("原始数组:");
    printArr(arr,len);
    heapSort(arr,len);
    printf("堆排序:");
    printArr(arr,len);
    return 0;
}