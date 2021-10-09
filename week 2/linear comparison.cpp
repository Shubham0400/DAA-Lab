#include<iostream>
using namespace std;
int main(void)
{
   int arr[20],n,i,num;
   for(int j=0;j<=2;j++)
   {
       int arr[50],i,n,cmp=0,l=0;  
        int key;
        cout<<"Enter the range"<<endl;
        cin>>n;
        cout<<"Enter the elements of the array"<<endl;
        for(i=0;i<=n-1;i++)
        {
            cin>>arr[i];
        }
        cout<<"Enter the key element"<<endl;
        cin>>key;
        for(i=0;i<=n-1;i++)
        {
            cmp++;
            if(key==arr[i])
            {
                l++;
                break;
            }
        }
        if(l!=0)
        {
            cout<<" Present\n"<<key<<endl;
            cout<<"\nTotal no of comparisons "<<cmp<<endl;
        }
        else
        {
            cout<<key<<"\nNot Found"<<endl;
            cout<<"\nTotal no of comparisons "<<n<<endl;
        }
   }
    return 0;
}