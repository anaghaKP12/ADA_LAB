#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void binary_search(int* arr,int key, int low, int high){
	count++;
	if (low<=high){
		int mid = (high+low)/2;
		if (arr[mid]==key) return;
		else if (arr[mid]>key) binary_search(arr,key,low,mid-1);
		else binary_search(arr,key,mid+1,high);
	}
}


void main(){
	int n,i,key;
	int* arr;
	
	srand(time(0));
	FILE *f1,*f2,*f3;
	
	f1 = fopen("binary_best.txt","w");
	f2 = fopen("binary_worst.txt","w");
	f3 = fopen("binary_avg.txt","w");
	
	for(n=10;n<=1000000;n*=10){
		arr = (int*)malloc(n*sizeof(int));
		
		for(i=0;i<n;i++){
			arr[i] = i+10;
		}
		
		//Best Case
		count=0;
		key = arr[(n-1)/2] = 9999;
		binary_search(arr,key,0,n-1);
		fprintf(f1,"%d\t%d\n",n,count);
		
		//Worst Case
		count=0;
		key = -1;
		binary_search(arr,key,0,n-1);
		fprintf(f2,"%d\t%d\n",n,count);
		
		//Average Case
		count=0;
		key = rand()%100;
		binary_search(arr,key,0,n-1);
		fprintf(f3,"%d\t%d\n",n,count);
	}
	
	fclose(f1); fclose(f2); fclose(f3);
}
/*command.txt*/
/*set title 'binary search'
set xrange[10:1000000]
set yrange[1:21]
set xlabel 'Input size(n)'
set ylabel 'Operation count'
set style data linespoints
plot 'binary_best.txt' title 'Best case','binary_worst.txt' title 'Worst case','binary_avg.txt' title 'Average case'
*/