#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> *mat;
class result{
    public:
        vector<int> distance;
        vector<int> pathtaken;
};
class qnode{
    public:
        int to;
        int cost;
        qnode(int t,int c){
            this->to = t;
            this->cost = c;
        }
};
struct CompareCost {
    bool operator()(qnode const& p1, qnode const& p2)
    {
        return p1.cost > p2.cost;
    }
};
void findTheShortestPath(vector<vector<int>> *,int);
result DijkstraAlgo(vector<vector<int>> *,int);
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int v,init;
    cin >> v;
    mat = new vector<vector<int>>(v,vector<int>(v,0));
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin >> (*mat)[i][j];
        }
    }
    cin >> init;
    findTheShortestPath(mat,init-1);
}
void findTheShortestPath(vector<vector<int>> *g,int start){
    result res = DijkstraAlgo(g,start);
     for(int i=0;i<(*g).size();i++){
         vector<int> path;
         for(int at = i;at != -1;at = res.pathtaken[at]){
             path.push_back(at);
         }
         for(int j=path.size()-1;j>=0;j--){
             cout<<path[j]+1<<" ";
         }
         cout << ":" << res.distance[i]<<endl;
     }
}
result DijkstraAlgo(vector<vector<int>> *g,int start){
    vector<int> visited((*g).size(),0),dist((*g).size(),99999),prev((*g).size(),-1);
    priority_queue<qnode,vector<qnode>,CompareCost> que;
    dist[start] = 0;
    que.push(qnode(start,0));
    while(!que.empty()){
        qnode obj = que.top();
        que.pop();
        visited[obj.to] = 1;
        if(obj.cost > dist[obj.to]) continue;
        for(int i=0;i<(*g).size();i++){
            if((*g)[obj.to][i]){
                if(visited[i]) continue;
                int newdist = obj.cost + (*g)[obj.to][i];
                if(newdist < dist[i]){
                    dist[i] = newdist;
                    prev[i] = obj.to;
                    que.push(qnode(i,newdist));
                }
            }
        } 
    }
    result res;
    res.distance = dist;
    res.pathtaken = prev;
    return res;
}