#include<stdio.h>
#include<conio.h>
int main()
{
	int arr[100],temp,n,i,j,min;
	printf("Enter n value : ");
	scanf("%d",&n);
	printf("Enter the array value : ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++)
	{	
		min = i;
		for(j=i+1;j<n;j++)
		{
			if(arr[min]>arr[j])
			{
				min = j;
			}
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
	}
	printf("After sorting...");
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
}
