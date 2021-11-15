#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> *mat;
class result{
    public:
        vector<int> distance;
        vector<int> pathtaken;
};
class edge{
    public:
        int from;
        int to;
        int cost;
        edge(int a,int b,int c){
            this->from = a;
            this->to = b;
            this->cost = c;
        }
};
void findTheShortestPath(vector<vector<int>> *,int);
result BellmanFordAlgo(vector<vector<int>>*,int);
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
    return 0;
}
void findTheShortestPath(vector<vector<int>> *g,int start){
    result res = BellmanFordAlgo(g,start);
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
result BellmanFordAlgo(vector<vector<int>>*g,int start){
    vector<int> dist((*g).size(),99999),prev((*g).size(),-1);
    vector<edge> edgeList;
    for(int i=0;i<(*g).size();i++){
        for(int j=0;j<(*g).size();j++){
            if((*g)[i][j]){
                edgeList.push_back(edge(i,j,(*g)[i][j]));
            }
        }
    }
    dist[start] = 0;
    for(int i=0;i<(*g).size()-1;i++){
        for(int j=0;j<edgeList.size();j++){
                if(dist[edgeList[j].to]>dist[edgeList[j].from]+edgeList[j].cost){
                    prev[edgeList[j].to] = edgeList[j].from;
                    dist[edgeList[j].to]=dist[edgeList[j].from]+edgeList[j].cost;
                }
        }
    }
    for(int i=0;i<(*g).size()-1;i++){
        for(int j=0;j<edgeList.size();j++){
                if(dist[edgeList[j].to]>dist[edgeList[j].from]+edgeList[j].cost){
                    dist[edgeList[j].to] = -9999;
                }
        }
    }
    result res;
    res.distance = dist;
    res.pathtaken = prev;
    return res;
}