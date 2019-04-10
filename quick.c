#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int quiksort(int a[],int beg,int end)
{
	if(beg>=end)
		return 0;
		
	int pivot=beg;
	int i=beg+1;
	int j=end;
	int c1=0,c2=0,c3=0;
	
	while(i<=j)
	{
		while(a[i]<=a[pivot] && i<=j)
		{
			i++;
			c1++;
		}
		
		while(a[j]>a[pivot] && j>=i)
		{
			j--;
			c1++;
		}
		
		if(i<j) swap(&a[i],&a[j]);
	}
	
	swap(&a[j],&a[pivot]);
	pivot=j;
	
	c2 = quiksort(a,beg,pivot-1);
	c3 = quiksort(a,pivot+1,end);
	return c1+c2+c3;		// Total no. of comparisons
}

void complexity()
{
	int i,j,c1,c2;
	int a[256];
	float n1,n2;
	
	printf("\n   \t\t  Ascending/Descending   \t\t  Random\n");
	printf("Input size   comparisons RateOfGrowth ratio  comparisons RateOfGrowth ratio \n");
	
	for(i=8;i<=256;i=i*2)
	{
		for(j=0;j<i;j++)
			a[j]=j;
		c1=quiksort(a,0,i-1);
		n1= i * i;
		printf("%5d \t\t%5d  \t  %8.2f   %6.2f",i,c1,n1,n1/c1);
		
		for(j=0;j<i;j++)
			a[j]=(int)random()%1000;
		c2=quiksort(a,0,i-1);
		n2= i * log2(i);
		printf("\t%5d \t%8.2f \t%4.2f\n",c2,n2,n2/c2);
	}
	
	printf("\nComplexity of Quick sort is n*n for ascending/descending order and n*log(n) for all other cases\n\n");
	return;	
}
	
//Utility functions
void readArray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
}

void printArray(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
}

int main()
{
	int size,i,ch,comp=0;
	int arr[100];
	
	while(1)
	{
		printf("\nQuicksort    1: Correctness   2: Complexity    3: Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
		
		case 1: printf("Enter the array size : ");
				scanf("%d",&size);
				printf("\nEnter the array elements : ");
				readArray(arr,size);
				printf("\nEntered Array : ");
				printArray(arr,size);
				comp = quiksort(arr,0,size-1);
				printf("\nArray elements after QuickSort : ");
				printArray(arr,size);
				printf("\nNo.of comparisons = %d\n",comp);
				break;
		
		case 2: complexity();
				break;
			
		default: return 0;
		
		}
	
	}
	
	return 0;	
}


/*OUTPUT

Quicksort    1: Correctness   2: Complexity    3: Exit
Enter your choice : 1
Enter the array size : 8

Enter the array elements : 2 3 4 1 7 8 12 22 5

Entered Array : 2 3 4 1 7 8 12 5 
Array elements after QuickSort : 1 2 3 4 5 7 8 12 
No.of comparisons = 16

Quicksort    1: Correctness   2: Complexity    3: Exit
Enter your choice : 2

   		  Ascending/Descending   		  Random
Input size   comparisons RateOfGrowth ratio  comparisons RateOfGrowth ratio 
    8 		   28  	     64.00     2.29	   15 	   24.00 	1.60
   16 		  120  	    256.00     2.13	   44 	   64.00 	1.45
   32 		  496  	   1024.00     2.06	  130 	  160.00 	1.23
   64 		 2016  	   4096.00     2.03	  401 	  384.00 	0.96
  128 		 8128  	  16384.00     2.02	  932 	  896.00 	0.96
  256 		32640  	  65536.00     2.01	 1990 	 2048.00 	1.03

Complexity of Quick sort is n*n for ascending/descending order and n*log(n) for all other cases*/
