#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void bubbleSort(int* arr, int n){
	int swapped = 0;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			count++;
			if (arr[j]>arr[j+1]){
				swapped=1;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		if (!swapped) return;
	}
}

void main(){
    int n,i,*arr;
    printf("Enter the number of elements\n");
    scanf("%d" ,&n);
    arr = (int *)malloc(n*sizeof(int));
    printf("Enter the array elements\n");
    for(i=0;i<n;i++)
    scanf("%d" ,(arr+i));
    bubbleSort(arr,n);
    printf("The sorted array is :\n");
    for(i=0;i<n;i++)
    printf("%d\t",*(arr+i));
}