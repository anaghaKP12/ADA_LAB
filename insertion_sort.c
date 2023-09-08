#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int count;


void insertionSort(int *arr, int n) {
    count = 0;
    for(int i=1; i<n; i++) {
        int value = arr[i];
        int j= i-1;
        while(count++ && arr[j] > value) {
            arr[j+1] = arr[j];
            j--;
            if(j<0)
                break;
        }
        arr[j+1] = value;
    }
}
void main()
{
 
   int *arr,n;
   srand(time(NULL));
   printf("Enter the number of elements\n");
   scanf("%d" ,&n);
   arr = (int *)malloc(n*sizeof(int));
   printf("Enter the array elements\n");
   for(int i=0;i<n;i++)
   scanf("%d" ,&arr[i]);
   insertionSort(arr,n);
   printf("The sorted array is\n");
   for(int i=0;i<n;i++)
   printf("%d\t",arr[i]);
}

