#include <stdio.h>
#include<stdlib.h>
void magic_square(int **, int);

int main()
{
   int n;
   printf("Enter a number: ");
   scanf("%d",&n);
   int **arr;
   //allocate dynamic memory for rows and columns
   arr=calloc(n,sizeof(int *));
   for(int i=0;i<n;i++)
   {
       arr[i]=calloc(n,sizeof(int));
   }
   if(n==1)
   {
       arr[0][0]=1;
       printf("%d\n",arr[0][0]);
       return 0;
   }
   //if number is odd only, then create magic square else print error
   if(n&1)
   {
       magic_square(arr,n);
   }
   else
   {
       printf("Error : Please enter only positive odd numbers\n");
   }
}
void magic_square(int **arr, int n)
{
    int i,j,a=0,b=n/2;
    int val=1;
    // create a label to use whenever we want
    label:
    if(val<=n*n)
    {
        //insert val into arr[a][b] upto n*n -> 9 here
        arr[a][b]=val++;
        //change index to add next ele into arr
        //jump 1 index up and 1 right side
        a=(a+n-1)%n;
        b=(b+n+1)%n;
        //if we already added ele into that index, change index and goto label to insert ele
        //else directly goto label to insert element
        if(arr[a][b]!=0)
        {
            a=(a+n+2)%n;
            b=(b+n-1)%n;
            goto label;
        }
        else
        {
            goto label;
        }
    }
    //print the matrix elements
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
