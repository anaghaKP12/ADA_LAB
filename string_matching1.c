//String Matching
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int count = 0;

int stringmatching(char *text, char *pattern, int n, int m) {
    count = 0;
    for(int i=0; i<=n-m; i++)
     {
        int j=0;
        while(j<m)
         {
            count++;
            if(pattern[j] != text[i+j]) 
                break;
            j++;
        }
        if(j==m) {
            return count;
        }
    }
    
    return count;
}

void main()
{
    FILE *f1 =fopen("string_best.txt", "w");
    FILE *f2 =fopen("string_worst.txt", "w");
    FILE *f3 =fopen("string_avg.txt", "w");
     char *text=(char *)malloc(1000*sizeof(char));
     char * pattern;
     for(int i=0;i<1000;i++)
     *(text+i) = 'a';
     int m,n;
      n=1000;
      m=10;
      for(m=10;m<=1000;m=(m<100)?m+10:m+100)
      {
        pattern = (char *)malloc(m*sizeof(char));
        //Best case
        for(int i=0; i<m; i++)
            pattern[i] = 'a';
            count=0;
            stringmatching(text, pattern, n,m); 
            fprintf(f1, "%d\t%d\n", m, count);
            
            count = 0;
            //worst case
             count=0;
             pattern[m-1] = 'b';
             stringmatching(text, pattern, n,m); 
             fprintf(f2, "%d\t%d\n", m, count);

             //Average Case
            for(int i=0; i<m; i++)
            pattern[i] =97+ rand()%3;
            count=0;
            stringmatching(text, pattern, n,m); 
            fprintf(f3,"%d\t%d\n", m, count);
            count=0;
            free(pattern);
      }

}

/*command.txt
set title 'String matching'
set xrange[10:1000]
set yrange[10:250500]
set xlabel 'Input size(n)'
set ylabel 'Operation count'
set style data linespoints
plot 'string_best.txt' title 'best case','string_worst.txt' title 'worst case','string_avg.txt' title 'average case'*/
