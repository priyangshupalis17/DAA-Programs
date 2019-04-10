    #include<stdio.h>
    int x,y,u,v,n,i,j,N=1;
    int visited[10],min,mincost=0,cost[10][10];
    
    int main() {
	for(int m=0;m<10;m++)
		visited[m]=0;
    	printf("\n Enter the number of nodes:");	//No. of vertices
    	scanf("%d",&n);
    	printf("\n Enter the adjacency matrix:\n");	//Adjacency matrix
    	for (i=1;i<=n;i++)
    	  for (j=1;j<=n;j++) {
    		scanf("%d",&cost[i][j]);
    		if(cost[i][j]==0)
    		    cost[i][j]=999;
    	}
    	visited[1]=1;
    	printf("\n");
    	while(N<n) {
    		for (i=1,min=999;i<=n;i++)
    		   for (j=1;j<=n;j++)
    		    if(cost[i][j]<min)
    		     if(visited[i]!=0) {
    			min=cost[i][j];
    			x=u=i;
    			y=v=j;
    		}
    		if(visited[u]==0 || visited[v]==0) {
    			printf("\n Edge %d:(%d %d) cost:%d",N++,x,y,min);	
    			mincost+=min;
    			visited[y]=1;
    		}
    		cost[x][y]=cost[y][x]=999;
    	}
    	printf("\n Minimun cost=%d",mincost);		//sum of weight of MST
    	
    }
