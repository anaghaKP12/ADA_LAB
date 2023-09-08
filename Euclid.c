#include<stdio.h>
#include<stdlib.h>

int euclid(int m,int n)
{
    while(n!=0){
    int r = m%n;
    m = n;
    n = r;
    }
    return m;

}

int consecutive(int m,int n)
{
    int min = m;
    if(n<min)
    min = n;
    while(1)
    {
        if(m%min == 0)
        {
        if(n%min == 0)
        return min;
        min-=1;
        }
        min-=1;
    }
        
}

int modified_euclid(int m,int n)
{
    while(n>0)
    {
        if(n>m)
        {
            int temp = m;
            m = n;
            n = temp;
        }
        m = m-n;
    }
    return m;
}

void main()
{
    int m,n,ch;
    printf("Enter the two numbers\n");
    scanf("%d%d" ,&m,&n);
    
    while(1)
    {
        printf("Enter the choice\n1.Euclid\n2.Consecutive Integer\n3.Modified Euclid\n");
    scanf("%d" ,&ch);
    switch(ch)
    {
        case 1:printf("Euclid : %d\n",euclid(m,n));break;
        case 2:printf("COnsecutive : %d\n",consecutive(m,n));break;
        case 3:printf("Modified : %d\n",modified_euclid(m,n));break;
        default:exit(0);

    }
    }
}
