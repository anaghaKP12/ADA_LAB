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
	
	FILE *fp;
	//system("rm a.txt");
	fp = fopen("selection.txt","w");
	
	for(n=10;n<1000;n+=100){
		arr = (int*)malloc(n*sizeof(int));
		
		//Operation Count is the same for all cases
		count=0;
		for(i=0;i<n;i++){
			arr[i] = rand()%100;
		}
		selectionSort(arr,n);
		fprintf(fp,"%d\t%d\n", n, count);
	}
	
	fclose(fp);
}
/*command.txt*/
/*set title 'selection_sort'
set xrange[10:1000]
set yrange[45:413595]
set xlabel 'Input size(n)'
set ylabel 'Operation count'
set style data linespoints
plot 'selection.txt' title 'selection_sort'
*/
