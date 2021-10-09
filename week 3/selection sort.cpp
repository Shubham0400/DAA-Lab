#include<iostream>
using namespace std;
int main()
{
    int i,n,x,arr[20],j,q=0,t,temp;
    	cout<<"\nTest Case:-"<<endl;
        cin>>x;
    for(t=0;t<=x-1;t++)
    {
    
        cout<<"\nEnter the number of elements"<<endl;
        cin>>n;
        cout<<"\nEnter the elements of array"<<endl;
        for(i=0;i<=n-1;i++)
        {
            cin>>arr[i];
        }
        q=0;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(arr[j]<arr[i])
                {
                     temp=arr[j];
                    arr[j]=arr[i];
                    arr[i]=temp;
                    q++;
                }
            }
        }
        cout<<"\nElements after sorting"<<endl;
        for(i=0;i<=n-1;i++)
        {
            cout<<arr[i]<<endl;
        }
        cout<<"\nComparison:"<<q<<endl;
        cout<<"\nSwaps:"<<n-1<<endl;
    }
    return 0;
}