#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int binary_search(int* arr,int key, int low, int high){
	if (low<=high){
		int mid = (high+low)/2;
		if (arr[mid]==key) return mid;
		else if (arr[mid]>key)  return binary_search(arr,key,low,mid-1);
		else return binary_search(arr,key,mid+1,high);
	}
}


void main(){
	    int *arr,key,n;
    printf("Enter the number of elements\n");
    scanf("%d" ,&n);
    arr = (int *)malloc(n*sizeof(int));
    printf("Enter the array elements in sorted order\n");
    for(int i=0;i<n;i++)
    scanf("%d" ,(arr+i));
    printf("Enter the key\n");
    scanf("%d" ,&key);
    int index = binary_search(arr,key,0,n-1);
    if(index==-1)
    
        printf("Key not found\n");
        else
        printf("Key present at %d\n",index);


}
