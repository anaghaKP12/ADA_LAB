//String Matching//testing for correctness
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//int count = 0;

int stringmatching(char *text, char *pattern, int n, int m) {
    //count = 0;
    for(int i=0; i<=n-m; i++)
     {
        int j=0;
        while(j<m)
         {
            //count++;
            if(pattern[j] != text[i+j]) 
                break;
            j++;
        }
        if(j==m) {
            return i;
        }
    }
    
    return -1;
}

void main()
{
   char *text,*pattern;
   int m,n;
   printf("Enter the text length\n");
    scanf("%d" ,&n);
    text = (char *)malloc(n*sizeof(char));
    printf("Enter the pattern length\n");
    scanf("%d" ,&m);
    pattern = (char *)malloc(m*sizeof(char));
    printf("Enter the text\n");
    scanf("%s" ,text);
    printf("Enter the pattern\n");
    scanf("%s" ,pattern);
    int index = stringmatching(text,pattern,n,m);
    if(index == -1)
    printf("Pattern not found\n");
    else
    printf("Pattern found at %d\n",(index+1));



}

