#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void selectionSort(int* arr, int n){
	int small;
	for(int i=0;i<n-1;i++){
		small=i;
		for(int j=i+1;j<n;j++){
			count++;	
			if (arr[j]<arr[small])
				small=j;
		}
		if (small!=i){
			int temp = arr[i];
			arr[i] = arr[small];
			arr[small]=temp;
		}
	}
}

void main(){
	int i,n;
	int *arr;
	printf("Enter the number of elements\n");
    scanf("%d" ,&n);
    arr = (int *)malloc(n*sizeof(int));
    printf("Enter the array elements\n");
    for(int i=0;i<n;i++)
    scanf("%d" ,(arr+i));
    selectionSort(arr,n);
    printf("The sorted array is \n");
    for(int i=0;i<n;i++)
    printf("%d\t",*(arr+i));

    system("gnuplot>load 'command.txt'");

}

