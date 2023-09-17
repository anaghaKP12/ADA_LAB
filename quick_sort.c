#include<stdio.h>

#include<stdlib.h>





int split;



void swap(int *p1,int *p2)

{

    int temp = *p1;

    *p1 = *p2;

    *p2 = temp;

}



int partition(int * arr,int l,int r)

{

    int pivot=arr[l],b=l,e=r+1,count=0;



    do

    {

        do

        {

            count++;

            if( arr[++b]>=pivot )

                break;

        } while ( b<r );



        do

        {

            count++;

            if( arr[--e]<=pivot )

                break;

        } while ( e>l );



        if( b<e )

            swap( &arr[b],&arr[e] );

    } while ( b<e );



    swap( &arr[e],&arr[l] );



    split=e;

    return count;

}





int Quicksort(int * arr,int l,int r)

{

   if( l>=r )

      return 0;

   int cnt =  partition(arr,l,r);

   int s=split;

   return ( cnt + Quicksort(arr,l,(s-1)) + Quicksort(arr,(s+1),r) );

}



void main()

{

   FILE *fp1,*fp2;

   fp1 = fopen("best_qs.txt","w");

   fp2 = fopen("worst_qs.txt","w");

  // fp3 = fopen("general_qs.txt","w");

   int *arr,i;





   for(int n=10; n<=200 ; n+=10 )

   {

      arr=(int *)malloc(sizeof(int)*n);



      //best case : split at median position (n/2 or (n+1))

      for( i=0 ; i<n ; i++)

          arr[i] = 7;

      fprintf(fp1,"%d %d\n",n,Quicksort(arr,0,n-1));



      //worst case : ascending order ( split on every element till last 2nd element in ascending order => skew recursion )

      for( i=0; i<n ; i++ )

          arr[i] = i+1;

      fprintf(fp2,"%d %d\n",n,Quicksort(arr,0,n-1));



      //general case

      //for( i=0 ; i<n ; i++ )

       //   arr[i] = rand()%n;

     // fprintf(fp3,"%d %d\n",n,Quicksort(arr,0,n-1));



      free(arr);

   }

   fclose(fp1);

   fclose(fp2);

  // fclose(fp3);

  // system("gnuplot>load command_qs.txt");

}