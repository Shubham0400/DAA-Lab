#include<bits/stdc++.h>
using namespace std;
bool DFS(vector<vector<int>> *,vector<int> *, int, int);
vector<vector<int>> *mat;
vector<int> *visited;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int V,to,from;
    cin >> V;
    mat = new vector<vector<int>>(V,vector<int>(V,0));
    visited = new vector<int>(V,0);
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin >> (*mat)[i][j];
        }
    }
    cin >> to >> from;
    cout << (DFS(mat,visited,to,from) ? "Yes Path Exists" : "No Such Path Exists") << endl;

}
bool DFS(vector<vector<int>> *mat,vector<int> *v, int to, int from){
    if((*v)[to]) return false;

    (*v)[to] = 1;
    //cout << to;
    if(to == from) return true;

    for(int i=0;i<(*mat).size();i++){
        if((*mat)[to][i]){ 
            if(DFS(mat,v,i,from)) return true;
        }
    }

}