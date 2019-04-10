#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;


class Edge
{
	public:
		int source,dest,weight;
};

void kruskal(Edge* input_edges,int n,int no_edges);
bool compare(Edge,Edge);
int findParent(int cur,int *parent);

int main()
{
			
	int n,a[10][10],no_edges=0,count=0;
	
	cout<<"\n\tEnter the number of vertices:\t"<<endl;
	cin>>n;
	
	cout<<"\n\tEnter the adjacency matrix:\n";
	cout<<"\tEnter 0 if there is no edge\n";
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
				if(a[i][j]==0)
					a[i][j]=100;
				else 
					no_edges++;
			}
	//edges=sortEdges(a,n);		
	//kruskal(a,n,edges);
	Edge* input_edges= new Edge[no_edges];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(a[i][j]!=100)
				{			
					input_edges[count].source=i;
					input_edges[count].dest=j;
					input_edges[count++].weight=a[i][j];	
				}	
		}
	
	kruskal(input_edges,n,no_edges);
	
	return 0;		
}

void kruskal(Edge* input_edges,int n,int no_edges)
{
	/*input: an array of class Edge which contains source,dest&weight
	       ,n(number of vertices) and no_edges
	Output: Kruskal's MST */

	/*sort the edges based on their weights*/
	sort(input_edges,input_edges+no_edges,compare);
	
	Edge* output= new Edge[n-1];
	int count=0,i=0,*parent=new int[n];
	
	/*parent array will store the parent vertex of each vertex*/
	for(int j=0;j<n;j++)
		parent[j]=j;
		
	while(count!=n-1)
	{
		Edge current_edge=input_edges[i];
	
	/*Check if current_edge can be added to mst(output)
			(Check if it forms a cycle)*/
	int source_parent=findParent(current_edge.source,parent);
	int dest_parent=findParent(current_edge.dest,parent);
		if(source_parent!=dest_parent) /*else cycle will be formed*/
		{
			output[count++]=current_edge;
			parent[source_parent]=dest_parent;
		}
		i++;
		//count++;	
	}
	
	
	int mst[n][n];
	/*set all values to zero initially*/
	for(int k=0;k<n;k++)
		memset(mst[k],0,sizeof(mst));
	
	/*create the MST adj. matrix*/
	for(int j=0;j<n;j++)
		//for(int k=0;k<n;k++)
		{
			mst[output[j].source][output[j].dest]=output[j].weight;
			mst[output[j].dest][output[j].source]=output[j].weight;			
		}	
	
	/* display the MST */
	cout<<"\nKruskal's MST is:\n";
	for(int j=0;j<n;j++)
		{
		for(int k=0;k<n;k++)	
			cout<<mst[j][k]<<" ";
		cout<<endl;
		}
		
	cout<<endl<<" source\t"<<" dest\t"<<"weight"<<endl;
	for(int j=0;j<n-1;j++)
	{
		printf("%6d\t%6d\t%6d\n",output[j].source,output[j].dest,output[j].weight);
		//cout<<output[j].source<<" "<<output[j].dest<<" "<<output[j].weight<<endl;		
	}
}

bool compare(Edge e1,Edge e2)
{
	return e1.weight<e2.weight;
}

int findParent(int cur,int *parent)
{
	if(parent[cur]==cur)
		return cur;
	return findParent(parent[cur],parent);
}


	/*OUTPUT:
Enter the number of vertices:	
4

	Enter the adjacency matrix:
	Enter 0 if there is no edge
0 999 3 999 
2 0 999 999
999 7 0 1
6 999 999 0

Kruskal's MST is:
0 2 3 0 
2 0 0 0 
3 0 0 1 
0 0 1 0 

 source	 dest	weight
     2	     3	     1
     1	     0	     2
     0	     2	     3
*/
