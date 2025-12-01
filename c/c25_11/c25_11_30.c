#include <stdio.h>

void sort(int* arr,int size)
{
    int temp = 0;
    for(int i = 0;i < size;i ++)
    {
        for(int j = i + 1;j < size;j ++)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {1,4,3,9,4,2};
    int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr,size);
    for(int i = 0;i < size;i ++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}