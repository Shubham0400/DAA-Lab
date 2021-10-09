#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        
        sort(arr,arr+n);
        int l=0,r=n-1,f=0;
        while(l<r)
        {
            if(arr[l]+arr[r]==key)
                {
                    cout<<arr[l]<<" "<<arr[r]<<endl;
                    f=1;
                    break;
                }
            else if(arr[l]+arr[r]<key)
                l++;
            else
                r--;
        }
        if(!f)
            cout<<"No Such Element Exist"<<endl;
    }
    return 0;
}