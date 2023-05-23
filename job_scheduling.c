Pseudo Code

/*
FUNCTION findMax(a[], n):
    max = 0
    FOR i = 0 to n-1:
        IF a[i] > max:
            max = a[i]
    RETURN max
FUNCTION setValues(a[], n):
    FOR i = 0 to n-1:
        a[i] = 0
FUNCTION setProfit(a[], n, p):
    FOR i = 0 to n-1:
        IF a[i] == 0:
            a[i] = p
            BREAK
FUNCTION main():
    DECLARE profit[20], dl[20], ts[10]
    DECLARE maxdl, p, n, temp, i, j
    PRINT "Enter the total number of Jobs"
    READ n
    PRINT "Enter the Deadlines of Jobs"
    FOR i = 0 to n-1:
        READ dl[i]
    PRINT "Enter the Profits of Jobs"
    FOR i = 0 to n-1:
        READ profit[i]
    maxdl = findMax(dl, n)
    setValues(ts, maxdl)
    FOR i = n-1 DOWNTO 1:
        FOR j = 0 to i-1:
            IF profit[j] < profit[j+1]:
                SWAP profit[j] with profit[j+1]
                SWAP dl[j] with dl[j+1]
    FOR i = 0 to n-1:
        IF ts[dl[i]-1] == 0:
            ts[dl[i]-1] = profit[i]
        ELSE:
            setProfit(ts, dl[i]-1, profit[i])
    p = 0
    FOR i = 0 to maxdl-1:
        p = p + ts[i]
    PRINT "Maximum Profit is ", p
END FUNCTION
*/



#include<stdio.h>

int findmax(int a[],int n)
{
	int i,max=0;
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	return max;
}

void setValues(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		a[i]=0;
	}
}

void setProfit(int a[],int n,int p)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			a[i]=p;
			break;
		}
	}
}

int main()
{
	int profit[20];
	int dl[20];
	int maxdl;
	int p=0;
	int n,temp,i,j;
	printf("Enter the total number of Jobs\n");
	scanf("%d",&n);
	
	printf("Enter the Deadlines of Jobs\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&dl[i]);
	}
	
	printf("Enter the Profits of Jobs\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&profit[i]);
	}
	maxdl = findmax(dl,n);
	int ts[10];
	setValues(ts,maxdl);
	
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(profit[j] < profit[j+1])
			{
				temp = profit[j];
				profit[j] = profit[j+1];
				profit[j+1] = temp;
			
				temp = dl[j];
				dl[j] = dl[j+1];
				dl[j+1] = temp;
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		if(ts[dl[i]-1]==0)
		{
			ts[dl[i]-1] = profit[i];
		}
		else
		{
			setProfit(ts,dl[i]-1,profit[i]);
		}
	}
	
	for(i=0;i<maxdl;i++)
	{
		p=p+ts[i];
	}
	
	printf("Maximum Profit is %d",p);
	return 0;
}

	
		
		
	 
