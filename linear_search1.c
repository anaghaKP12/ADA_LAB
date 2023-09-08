#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void linearSearch(int* arr,int key, int n){
	for(int i=0; i<n; i++){
		count++;
		if (arr[i]==key) return;
	}
}


void main(){
	int n,i,key;
	int* arr;
	
	srand(time(0));
	FILE *f1,*f2,*f3;
	
	f1 = fopen("linear_best.txt","w");
	f2 = fopen("linear_worst.txt","w");
	f3 = fopen("linear_avg.txt","w");
	
	for(n=10;n<=1000;n=(n<100)?n+10:n+100){
		arr = (int*)malloc(n*sizeof(int));
		
		for(i=0;i<n;i++){
			arr[i] = rand()%100;
		}
		
		//Best Case
		count=0;
		key=arr[0];
		linearSearch(arr,key,n);
		fprintf(f1,"%d\t%d\n",n,count);
		
		//Worst Case
		count=0;
		key = arr[n-1] = 9999;
		linearSearch(arr,key,n);
		fprintf(f2,"%d\t%d\n",n,count);
		
		//Average Case
		count=0;
		key = arr[n/2] = 9999;
		linearSearch(arr,key,n);
		fprintf(f3,"%d\t%d\n",n,count);
	}
	
	fclose(f1); 
    fclose(f2); 
    fclose(f3);
	//system("gnuplot>load 'command.txt'");
}
/*command.txt*/
/*
set title 'linear search'
set xrange[10:1000]
set yrange[1:900]
set xlabel 'Input size(n)'
set ylabel 'Operation count'
set style data linespoints
plot 'linear_best.txt' title 'Best case','linear_worst.txt' title 'Worst case','linear_avg.txt' title 'Average case'
*/