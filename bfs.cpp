#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

int visited[100]= {0};
queue<int> q;

void BFS(int[100][100], int, int);

int main(){
	int n;
	cout<< "ENTER NUMBER OF EDGES: ";
	cin>>n;
	int G[100][100];
	cout<< "ENTER THE MATRIX:\n";
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin>> G[i][j];
	int v;
	cout << "ENTER THE SOURCE VERTEX: ";
	cin>> v;
	
	cout<< "TRAVERSAL ORDER IS: \n";
	
	BFS(G,n,v);
	for(int k=0;k<n;k++)
	{
		if(visited[k]==0)
			BFS(G,n,k);
	}
	/*int k=v;
	do
	{
		if(visited[k]==0)
			BFS(G,n,k);
		k=(k+1)%n;
	}while(k!=v);*/
	return 0;
}

void BFS(int G[100][100], int n, int v){
	if (visited[v] == 1)
		return;
	q.push(v);
	visited[v] = 1;
	while(!q.empty())
    {
    	int top = q.front();
    	cout<< top<<"  ";
    	q.pop();
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0 && G[top][i])
            {
              // BFS(G,n, i);
  				q.push(i);
  				visited[i] =1;
            }
        }
    }
}

