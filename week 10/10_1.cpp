#include<bits/stdc++.h>
using namespace std;
int main()
{
int V;
cin>>V;
vector<int> T1(V), T2(V);
vector<pair<pair<int, int>, int>> ar;
for(int i = 0;i<V; i++)
cin>>T1[i];
for(int i = 0;i<V; i++)
cin>>T2[i];
for(int i = 0;i<V; i++)
ar.push_back({{T2[i], T1[i]}, i});
sort(ar.begin(),ar.end());
vector<int> answer;
int currst, preft;
currst = ar[0].first.second+1;
preft = ar[0].first.first;
answer.push_back(ar[0].second);
for(int i = 1;i<V;i++)
{
currst = ar[i].first.second;
if(preft <= currst)
{
answer.push_back(ar[i].second+1);
preft = ar[i].first.first;
}
}
cout<<"\nNo. of non-conflicting activities: 
"<<answer.size();
cout<<"\nList of selected activities:";
for(auto i : answer)
{
cout<<" "<<i;
}
return 0;
}