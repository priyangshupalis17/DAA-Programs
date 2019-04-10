#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int arr[50],n,sum,inc[50];

int promising(int i,int w,int total)
{
    return ((w+total)>=sum && ((w==sum)||(w+arr[i+1]<=sum)));
}

void subset(int i,int w,int total)
{
    if(promising(i,w,total))
    {
        if(w==sum)
        {
            cout<<"{\t";
            for(int i=0;i<n;i++)
                if(inc[i])
                    cout<<arr[i]<<" ";
            cout<<"\t}";
        }
        else
        {
            inc[i+1]=1;
            subset(i+1,w+arr[i+1],total-arr[i+1]);
            inc[i+1]=0;
            subset(i+1,w,total-arr[i+1]);
        }
    }
}
int main()
{
    int temp,total=0;
    cout<<"enter no.of elemnts\n";
    cin>>n;
    cout<<"enter the elemnts\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        total+=arr[i];
    }
    cout<<"enter sum\n";
    cin>>sum;
    for (int i=0;i<n;i++)
	  for (int j=0;j<n-1;j++)
	   if(arr[j]>arr[j+1]) {
		temp=arr[j];
		arr[j]=arr[j+1];
		arr[j+1]=temp;
	}
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n"<<total<<endl;
        if(total<sum)
            cout<<"subset not possible\n";
        else
        {
            for(int i=0;i<n;i++)
                inc[i]=0;
            subset(-1,0,total);
        }
}

/* OUTPUT:
enter no.of elemnts
6
enter the elemnts
5 10 15 12 16 18
enter sum
30
5 10 12 15 16 18 
76
{	5 10 15 	}{	12 18 	}
*/

