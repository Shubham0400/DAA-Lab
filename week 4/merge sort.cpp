#include<stdio.h>
void merge(int arr[],int F,int mid,int L)
{
	int i=F,j=mid+1,k = F,temp[100];
	while(i<=mid&&j<=L)
	{
		if(arr[i]<=arr[j])
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		temp[k] = arr[i];
		k++;
		i++;
	}
	while(j<=L)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}
	i=F;
	while(i<=L)
	{
		arr[i] = temp[i];
		i++;
	}
}
void Merge(int arr[], int F, int L)
{
	int mid;
	if(F<L)
	{
		mid = (F+L)/2;
		Merge(arr,F,mid);
		Merge(arr,mid + 1,L);
		merge(arr,F,mid,L);
	}
}
int main()
{
	int arr[100];
	int n,i;
	printf("\n\tEnter the number of elements : ");
	scanf("%d",&n);
	printf("\n\tEnter data :\n");
	for(i=0;i<n;i++)
	{
		printf("\t");
		scanf("%d",&arr[i]);
	}
	Merge(arr,0,n-1);
	printf("\n\tArray after merge sort :\n\t",arr[i]);
	
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}