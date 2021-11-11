#include<bits/stdc++.h>
using namespace std;
bool isBipartite(vector<vector<int>>*,vector<int> *);
vector<vector<int>> *mat;
vector<int> *color;

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int v;
    cin >> v;
    mat = new vector<vector<int>>(v,vector<int>(v,0));
    color = new vector<int>(v,0);
    for (int i = 0; i < v; i++){
        for(int j=0;j<v;j++){
            cin >> (*mat)[i][j];
        }
    }
    cout << (isBipartite(mat,color) ? "Yes Bipartite": "Not Bipartite") << endl;
    return 0;
}
bool isBipartite(vector<vector<int>> *mat,vector<int> *color){
    queue<int> q;
    q.push(0);
    (*color)[0] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<(*mat).size();i++){
            if((*mat)[x][i]){
                if((*color)[i]){
                    if((*color)[i] == (*color)[x] && i!=x){
                        return false;
                    }
                }else{
                    (*color)[i] = ((*color)[x]==1 ? 2 : 1);
                    q.push(i);
                }
            }
        }
    }
    return true;
}