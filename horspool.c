#include<stdio.h>
#include<string.h>

int main()
{
	int table[100],table2[20],i,j,m,n,k=0,flag=0;
	char text[100],pattern[20];
	printf("Enter the text : ");			//Text
	scanf("%s",text);
	printf("Enter pattern to be searched: ");	//Text to be searched
	scanf("%s",pattern);
	n=strlen(text);					//calculating length of the text
	m=strlen(pattern);				//calculating length of the text to be searched
	for(i=0;i<=n-1;i++)
		table[i]=m;
	i=0;
	for(j=m-1;j>=0;j--)
		table2[j]=i++;
	i=m-1;
	while(i<=n-1)
	{
		k=0;
		while(k<=m-1 && pattern[m-1-k]==text[i-k])
			k++;
		if(k==m)
		{
			printf("The position of the pattern is %d.\n",i-m+2);	//printing the position from which the pattern matches
			flag=1;
			break;
		}
		++i;
	}
	
	if(!flag)
		printf("Pattern is not found in the given text.\n"); 		//if pattern not found
}
