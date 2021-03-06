#include<stdio.h>
#include<stdlib.h>
#define MAX 500
int n,c,weight[MAX],profit[MAX],vector [MAX][MAX],x[MAX];
int max(int,int);
void knapsack();
void printsoln();
int main()
{
    printf("Enter the number of weights:");
    scanf("%d",&n);
    printf("Enter the capacity of knapsack:");
    scanf("%d",&c);
    int i,j;
    printf("Enter the value of weights:");
    for(i=1;i<=n;i++)
    scanf("%d",&weight[i]);
    printf("Enter the value profits:");
    for(i=1;i<=n;i++)
    scanf("%d",&profit[i]);
    knapsack();
    printsoln();
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=c;j++)
        {
            printf("%2d ",vector[i][j]);
        }
        printf("\n");
    }
    printf("Maximum profit  is %d \n",vector[n][c]);
    printf("Objects considered are\n");
    for(i=1;i<=n;i++)
    if(x[i]==1)
    printf("object no=%d weight=%d profit=%d\n",i,weight[i],profit[i]);
    return 0;
}

int max(int a,int b)
{
    return a>b?a:b;
}
void knapsack()
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=c;j++)
        {
            if(i==0 || j==0)
            vector[i][j]=0;
            else if(j-weight[i]<0)
            vector[i][j]=vector[i-1][j];
            else
            vector[i][j]=max(vector[i-1][j],vector[i-1][j-weight[i]]+profit[i]);
        }
    }
}
void printsoln()
{
    int i=n,j=c;
    while(i!=0||j!=0)
    {
        if(vector[i][j]!=vector[i-1][j])
        {
        x[i]=1;
        j=j-weight[i];
    }
    i--;
}
}

/* OUTPUT

Enter the number of weights:4
Enter the capacity of knapsack:9
Enter the value of weights:4 5 2 3
Enter the value profits:20 12 10 25
 0  0  0  0  0  0  0  0  0  0 
 0  0  0  0 20 20 20 20 20 20 
 0  0  0  0 20 20 20 20 20 32 
 0  0 10 10 20 20 30 30 30 32 
 0  0 10 25 25 35 35 45 45 55 
Maximum profit  is 55 
Objects considered are
object no=1 weight=4 profit=20
object no=3 weight=2 profit=10
object no=4 weight=3 profit=25

*/
