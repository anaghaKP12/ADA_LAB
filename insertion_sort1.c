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
   FILE *f1,*f2,*f3;
 
   f1=fopen("insertion_best.txt","w");
   f2=fopen("insertion_worst.txt","w");
   f3=fopen("insertion_avg.txt","w");
   
    for(n=10;n<1000;n+=100){
		arr = (int*)malloc(n*sizeof(int));
		
		//Best Case
		count=0;
		for(int i=0;i<n;i++){
			arr[i] = (i==0) ? rand()%100 : arr[i-1]+rand()%10;
		}
		insertionSort(arr,n);
		fprintf(f1,"%d\t%d\n",n,count);
		
		//Worst Case
		count=0;
		for(int i=0;i<n;i++){
			*(arr+i) = n-i;
		}
		insertionSort(arr,n);
		fprintf(f2,"%d\t%d\n",n,count);
		
		//Average Case
		count=0;
		for(int i=0;i<n;i++){
			arr[i] = rand()%100;
		}
		insertionSort(arr,n);
		fprintf(f3,"%d\t%d\n",n,count);
	}
	
	fclose(f1); fclose(f3); fclose(f2);
}

/*command.txt
set title 'insertion sort'
set xrange[10:1000]
set yrange[9:413595]
set xlabel 'Input size(n)'
set ylabel 'Operation count'
set style data linespoints
plot 'insertion_best.txt' title 'best case' ,'insertion_worst.txt' title 'worst case','insertion_avg.txt' title 'Average case'
*/