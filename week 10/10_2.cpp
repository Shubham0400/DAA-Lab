#include<bits/stdc++.h>
using namespace std;
bool cmp( pair<pair<int , int>, int> a, pair<pair<int , 
int>, int> b)
{
if(a.first.first > b.first.first)
return true;
else if(a.second<b.second)
return true;
else
return false;
}
int main()
{
int V;
cin>>V;
vector<pair<pair<int , int>, 
int>> ar;
vector<int> T1(V), T2(V);
for(int i = 0; i<V;i++)
{
cin>>T1[i];
}
for(int i = 0; i<V;i++)
{
cin>>T2[i];
}
for(int i = 0; i<V;i++)
{
ar.push_back({{T2[i], 
T1[i]},i});
}
sort(ar.begin(), 
ar.end(),cmp);
vector<int> answer;
answer.push_back(ar[0].sec
ond);
int left = ar[0].first.first;
left = left -
ar[0].first.second;
for(int i = 1;i<V;i++)
{
if(ar[i].first.first <= left)
{
answer.push_back(ar[i].sec
ond);
left -= 
ar[i].first.second;
}
}
sort(answer.begin(), 
answer.end());
cout<<"\nMax number of 
tasks = "<<answer.size();
cout<<"\nSelected task 
numbers : ";
for(auto i : answer)
{
cout<<" "<<i+1;
}
return 0;
}