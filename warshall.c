/* program to implement the Warshall's Algorithm*/

#include<stdio.h>
#include<stdlib.h>

int graph[100][100];
int counter=0;
void warshall (int n)
{
    for(int k=1; k<=n; k++) 
    {
        for(int i=1; i<=n; i++) 
        {

            if(graph[i][k]!=0)
            {
                 for(int j=1; j<=n; j++)
                {// graph[i][j] = (graph[i][k] && graph[k][j]));
                  graph[i][j] = (graph[i][j] || (graph[i][k] && graph[k][j]));
                   counter++;
                }
            }
        }
    }
}


void main()
{

  int n;
  printf("Enter the number of vertices\n");
  scanf("%d" ,&n);
   printf("Enter the adjacecny matrix\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        scanf("%d" ,&graph[i][j]);
    }
    counter=0;
    warshall(n);
    printf("The tarnsitive closure is \n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        printf("%d " ,graph[i][j]);
        printf("\n");
    }

}
   


