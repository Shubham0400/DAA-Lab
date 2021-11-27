#include<stdio.h>
#include<malloc.h>
int Qcon(int *arr,int F,int L,int *cmp,int *shft)
{
int i,temp;
int p = arr[L];
int j = F-1;
for(i = F;i<L;i++)
{
if(++(*cmp)&&arr[i]<=p)
{
(*shft)++;
j++;
temp = arr[i];
arr[i] = arr[j];
arr[j] = temp;
}
}
(*shft)++;
temp = arr[L];
arr[L] = arr[j+1];
arr[j+1] = temp;
return j+1;
}
void Qdivide(int *arr, int F, int L,int *cmps, int 
*shfts)
{
int i;
if(F<L)
{
int ind = Qcon(arr,F,L,cmps,shfts);
Qdivide(arr,F,ind-1,cmps,shfts);
Qdivide(arr,ind+1,L,cmps,shfts);
}
}
int main()
{
int **arr,noc,*noe,i,j,*cmp,*shft;
scanf("%d",&noc);
arr = (int **)malloc(noc*sizeof(int *));
noe = (int *)malloc(noc*sizeof(int));
cmp = (int *) malloc(noc*sizeof(int));
shft = (int *) malloc(noc*sizeof(int));
for(i=0;i<noc;i++)
{
scanf("%d",noe+i);
*(arr+i) = (int 
*)malloc(*(noe+i)*sizeof(int));
for(j=0;j<*(noe+i);j++)
{
scanf("%d",*(arr+i)+j);
}
}
for(i=0;i<noc;i++)
{
*(cmp+i) = *(shft+i) = 0;
Qdivide(*(arr+i),0,*(noe+i)-
1,cmp+i,shft+i);
}
for(i=0;i<noc;i++)
{
printf("\n");
for(j=0;j<*(noe+i);j++)
{
printf("%d ",arr[i][j]);
}
printf("\ncomparisons = 
%d",*(cmp+i));
printf("\nswaps = %d",*(shft+i));
}
return 0;
}