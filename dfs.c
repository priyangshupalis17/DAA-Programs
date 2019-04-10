#include<stdio.h>
#include<stdlib.h>

void DFS(int);
int G[10][10],visited[10],n,count=0,k,indeg[10],flag[10],a[10][10];    //n is no of vertices and graph is sorted in array G[10][10]
 
int main()
{
    int i,j;
    printf("Enter number of vertices:");
   
	scanf("%d",&n);
 
    //read the adjecency matrix
	printf("\nEnter adjecency matrix of the graph:");
   
	for(i=0;i<n;i++)
       for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);
 
    //visited is initialized to zero
   for(i=0;i<n;i++)
        visited[i]=0;
 
    DFS(0);
   
   printf("TOPOLOGICAL ORDERING\n");
   printf("Enter the no of vertices: ");
	scanf("%d",&n);
 
	printf("Enter the adjacency matrix:-\n");
	for(i=0;i<n;i++){
		printf("Enter row %d\n",i+1);
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	}
    
    	for(i=0;i<n;i++){
        indeg[i]=0;
        flag[i]=0;
    }
 
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            indeg[i]=indeg[i]+a[j][i];
 
    printf("\nThe topological order is:");
 
    while(count<n) {
        for(k=0;k<n;k++)
        {
            if((indeg[k]==0) && (flag[k]==0)) {
                printf("%d ",(k+1));
                flag[k]=1;
            }
 
            for(i=0;i<n;i++) {
                if(a[i][k]==1)
                    indeg[k]--;
            }
        }
        count++;
    }

	return 0;
}
 
void DFS(int i)
{
    int j;
	printf("\n%d",i);
    visited[i]=1;
	
	for(j=0;j<n;j++)
       if(!visited[j]&&G[i][j]==1)
            DFS(j);
}
