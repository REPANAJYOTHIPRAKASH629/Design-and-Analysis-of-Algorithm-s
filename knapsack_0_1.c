#include<stdio.h>
int main()
{
	float w[20],v[20];
	float vd[20];
	int i,j,n;
	float benefit = 0.0,temp;
	float mw;
	float tw=0;
	
	
	printf("Enter the maximum weight : ");
	scanf("%f",&mw);
	
	printf("Enter the total number of items : ");
	scanf("%d",&n);
	
	printf("Enter the weight of the items\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&w[i]);
	}
	printf("Enter the values for items\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&v[i]);
	}
	
	
	// value density
	
	for(i=0;i<n;i++)
	{
	vd[i] = v[i]/w[i];
	}
	
	// sorting the value density
	
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if (vd[j]<vd[j+1])
			{
				temp = vd[j];
				vd[j] = vd[j+1];
				vd[j+1] = temp;
				
				temp = w[j];
				w[j] = w[j+1];
				w[j+1] = temp;
				
				temp  = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
			}
		}
	}
	
	
	for(i=0;i<n;i++)
	{
		if(tw+w[i] > mw)
		{
			continue;
		}
		tw = tw+w[i];
		benefit+=v[i];
	}
	printf("Benefit is %f ",benefit);
	return 0;
}
