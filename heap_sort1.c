#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

int count;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int *arr, int n, int i){
	int largest = i;
	int left = 2*i +1;
	int right = 2*i +2;
	
	if (left<n) 
    {
        count++;
        if(arr[left]>arr[largest])
        largest = left;
    }
	if (right<n)
      { 
        count++;
        if(arr[right]>arr[largest])
		largest = right;
      }
	if (largest!=i){
		swap(&arr[i],&arr[largest]);
		heapify(arr,n,largest);
	}
}

void heapSort(int* arr, int n){
	for(int i=n/2-1; i>=0; i--){
		heapify(arr,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}

void main(){
	int n,i;
	int *arr;
	
	FILE *f1,*f2,*f3;
	//system("rm a.txt b.txt w.txt");
	f1 = fopen("heap_best.txt","w");
	f2 = fopen("heap_worst.txt","w");
	f3 = fopen("heap_avg.txt","w");
	int k=3;
	for(n=3;n<=1024;n=(pow(2,k++)-1)){
		arr = (int*)malloc(n*sizeof(int));
		
		//Best Case
		count=0;
		for(i=0;i<n;i++){
			arr[i] = n-i+1;
		}
		heapSort(arr,n);
		fprintf(f1,"%d\t%d\n",n,count);
		
		//Worst Case
		count=0;
		heapSort(arr,n);
		fprintf(f2,"%d\t%d\n",n,count);
		
		//Average Case
		count=0;
		for(i=0;i<n;i++){
			arr[i] = rand()%100;
		}
		heapSort(arr,n);
		fprintf(f3,"%d\t%d\n",n,count);
	}
	
	fclose(f1); fclose(f3); fclose(f2);
}
/*command.txt
set title 'heap sort'
set xrange[3:1023]
set yrange[3:18038]
set xlabel 'Input size(n)'
set ylabel 'Operation count'
set style data linespoints
plot 'heap_best.txt' title 'best case','heap_worst.txt' title 'worst case','heap_avg.txt' title 'average case'*/