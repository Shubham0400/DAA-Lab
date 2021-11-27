#include<bits/stdc++.h>
using namespace std;
int main()
{
int V,t;
cin>>V;
vector<int> temp(V);
for(int i = 0;i<V;i++)
cin>>temp[i];
int mx = 
*max_element(temp.begin(),temp.end());
vector<int> countarray(mx+1, 0);
for(auto i : temp)
{
countarray[i]++;
}
int flag = 0;
for(auto i : countarray)
{
if(i>V/2)
{
auto tind = 
find(countarray.begin(), countarray.end(), i);
cout<<"\nyes\n"<<tind -
countarray.begin();
flag = 1;
break;
}
}
if(!flag)
cout<<"no";
return 0;
}