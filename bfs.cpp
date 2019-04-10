#include<bits/stdc++.h>
using namespace std;

int adj[10][10],n,visited[10]={0};
queue<int>q;

void BFS(int);
	
int main()
{
	cout<<"Enter the number of vertices : ";
	cin>>n;
	
	cout<<"Enter the matrix\n";
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>adj[i][j];
	
	int v;
	cout<<"Enter source vertex : ";
	cin>>v;
	
	cout<<"BFS : ";
	BFS(v);
	int count=1;
	for(int i=0;i<n;i++)
		if(visited[i]==0) {
			BFS(i);
			count++;
		}
	cout<<"Components : "<<count<<endl;
	return 0;
}

void BFS(int v)
{
	if(visited[v] == 1)
		return;
	
	q.push(v);
	visited[v] = 1;
	
	while(!q.empty())
	{
		int top = q.front();
		cout<<top<<" ";
		q.pop();
		
		for(int i=0;i<n;i++)
		{
			if(visited[i] == 0 && adj[top][i] == 1) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}
