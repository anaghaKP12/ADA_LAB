#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

void bubbleSort(int* arr, int n){
	for(int i=0;i<n-1;i++){
		int flag = 0;
		for(int j=0;j<n-1-i;j++){
			count++;
			if (arr[j]>arr[j+1]){
				flag = 1;
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		if (flag == 0) return;
	}
}

void main(){
	int n,i;
	int *arr;
	
	FILE *fp1,*fp2,*fp3;
	//system("rm a.txt b.txt w.txt");
	fp1 = fopen("bubble_best.txt","w");
	fp2 = fopen("bubble_worst.txt","w");
	fp3 = fopen("bubble_avg.txt","w");
	
	for(n=10;n<1000;n+=100){
		arr = (int*)malloc(n*sizeof(int));
		
		//Best Case
		count=0;
		for(i=0;i<n;i++){
			arr[i] = (i==0) ? rand()%100 : arr[i-1]+rand()%10;
		}
		bubbleSort(arr,n);
		fprintf(fp1,"%d\t%d\n",n,count);
		
		//Worst Case
		count=0;
		for(i=0;i<n;i++){
			arr[i] = 2*n - i;
		}
		bubbleSort(arr,n);
		fprintf(fp2,"%d\t%d\n",n,count);
		
		//Average Case
		count=0;
		for(i=0;i<n;i++){
			arr[i] = rand()%100;
		}
		bubbleSort(arr,n);
		fprintf(fp3,"%d\t%d\n",n,count);
	}
	
	fclose(fp1); fclose(fp3); fclose(fp2);
}
/*command.txt*/
/*set title 'bubble_sort'
set xrange[10:1000]
set yrange[9:413595]
set xlabel 'Input size(n)'
set ylabel 'Operation count'
set style data linespoints
plot 'bubble_best.txt' title 'best case','bubble_worst.txt' title 'worst case','bubble_avg.txt' title 'average case'
*/