#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mergesort(int[],int,int);
int merge(int[],int,int,int);
void complexity();

// Utility functions
void readArray(int[],int);    
void printArray(int[],int);

int main()
{
	int size,i,ch,comp=0;
	int arr[100];
	
	while(1)
	{
		printf("\nMergesort    1: Correctness   2: Complexity    3: Exit\n");
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
				comp = mergesort(arr,0,size-1);
				printf("\nArray elements after MergeSort : ");
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

int merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k=l, count=0;  // count is no. of comparisons
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 		 // Left and Right subarray

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
  	i=0; j=0;
  	
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j])   // Basic operation = comparison
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
        count++;
    } 
  
    while (i < n1)         		// Remaining elements in Left subarray
        arr[k++] = L[i++]; 
           
    while (j < n2) 				 // Remaining elements in Right subarray
        arr[k++] = R[j++]; 
        
    return count;
} 
  
int mergesort(int arr[], int l, int r) 
{ 
	int a=0, b=0, c=0;
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        a=mergesort(arr, l, m); 
        b=mergesort(arr, m+1, r); 
        c=merge(arr, l, m, r); 
    } 
    return a+b+c;
} 

void complexity()
{
	int i,j,c1,c2;
	int a[1024];
	float n1,n2;
	
	printf("\n   \t\t  Ascending/Descending   \t\t  Random\n");
	printf("Input size   comparisons RateOfGrowth ratio  comparisons RateOfGrowth ratio \n");
	
	for(i=8;i<=1024;i=i*2)
	{
		for(j=0;j<i;j++)
			a[j]=j;
		c1=mergesort(a,0,i-1);
		n1= i * log2(i);
		printf("%5d \t\t%5d  \t  %8.2f   %6.2f",i,c1,n1,n1/c1);
		
		for(j=0;j<i;j++)
			a[j]=(int)random()%1000;
		c2=mergesort(a,0,i-1);
		n2= i * log2(i);
		printf("\t%5d \t%8.2f \t%4.2f\n",c2,n2,n2/c2);
	}
	
	printf("\nComplexity of merge sort is n*log(n) for all cases\n\n");
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

/*OUTPUT
Mergesort    1: Correctness   2: Complexity    3: Exit
Enter your choice : 1
Enter the array size : 8

Enter the array elements : 6 5 9 1 2 3 0 4

Entered Array : 6 5 9 1 2 3 0 4 
Array elements after MergeSort : 0 1 2 3 4 5 6 9 
No.of comparisons = 15

Mergesort    1: Correctness   2: Complexity    3: Exit
Enter your choice : 2

   		  Ascending/Descending   		  Random
Input size   comparisons RateOfGrowth ratio  comparisons RateOfGrowth ratio 
    8 		   12  	     24.00     2.00	   16 	   24.00 	1.50
   16 		   32  	     64.00     2.00	   43 	   64.00 	1.49
   32 		   80  	    160.00     2.00	  114 	  160.00 	1.40
   64 		  192  	    384.00     2.00	  306 	  384.00 	1.25
  128 		  448  	    896.00     2.00	  733 	  896.00 	1.22
  256 		 1024  	   2048.00     2.00	 1725 	 2048.00 	1.19
  512 		 2304  	   4608.00     2.00	 3967 	 4608.00 	1.16
 1024 		 5120  	  10240.00     2.00	 8943 	10240.00 	1.15

Complexity of merge sort is n*log(n) for all cases*/
