#include<stdio.h>

void swap(int* a,int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int partition(int x[],int l,int r)
{
		int pivot = x[r];
		int j,i = l-1;
		for(j=l; j<r;j++)
		{
			if(x[j]<pivot)
			{
				i=i+1;
				swap(&x[i],&x[j]);
			}
		}
		swap(&x[i+1],&x[r]);
		return i+1;
}

void quicksort(int x[],int l,int r)
{
	if(l<r)
	{
		int p = partition(x,l,r);
		quicksort(x,l,p-1);
		quicksort(x,p+1,r);
	}
}

int main()
{
	int x[100];
	int i,n;
	
	printf("Enter the total number of elements in the array : ");
	scanf("%d",&n);
	
	printf("Enter the elements : ");

	for(i = 0;i<n;i++)
	{
		scanf("%d",&x[i]);
	}
	
	printf("Array elements before the sorting.");

	for(i=0;i<n;i++)
	{
		printf("%d  ",x[i]);
	}
	printf("\n");
	
	quicksort(x,0,n-1);
	
	printf("Array elements after the sorting.");
	
	for(i=0;i<n;i++)
	{
		printf("%d  ",x[i]);
	}
	return 0;
}
