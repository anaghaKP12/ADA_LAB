#include<stdio.h>
#include<stdlib.h>

int linear_search(int *arr,int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i] == key)
        return i;
    }
    return -1;
}

void main()
{
    int *arr,key,n;
    printf("Enter the number of elements\n");
    scanf("%d" ,&n);
    arr = (int *)malloc(n*sizeof(int));
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
    scanf("%d" ,(arr+i));
    printf("Enter the key\n");
    scanf("%d" ,&key);
    int index = linear_search(arr,n,key);
    if(index==-1)
    
        printf("Key not found\n");
        else
        printf("Key present at %d\n",index);
    
}