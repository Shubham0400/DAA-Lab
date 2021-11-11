#include<bits/stdc++.h>
using namespace std;
bool containCycle(vector<vector<int>> *,vector<int> *);
bool helper(vector<vector<int>> *,vector<int> *, int,int);
vector<vector<int>> *mat;
vector<int> *visited;
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int v;
    cin >> v;
    mat = new vector<vector<int>>(v,vector<int>(v,0));
    visited = new vector<int>(v,0);
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin >> (*mat)[i][j];
        }
    }
    cout << (containCycle(mat,visited) ? "Yes Cycle Exists" : "No Cycle Exists") << endl;
    return 0;
}

bool containCycle(vector<vector<int>>*mat,vector<int>*v){
    for(int i=0;i<(*mat).size();i++){
        delete visited;
        visited = new vector<int>((*mat).size(),0);
        if(helper(mat,v,i,i)) return true;
    }
    return false;
}
bool helper(vector<vector<int>> *mat,vector<int>*v,int vert,int rem){
    if((*v)[vert] && vert == rem) return true;
    if((*v)[vert]) return false;

    (*v)[vert] = 1;

    for(int i=0;i<(*mat).size();i++){
        if((*mat)[vert][i]){
            if(helper(mat,v,i,rem)) return true;
        }
        
    }
    return false;
}