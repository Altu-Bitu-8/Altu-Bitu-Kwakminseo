#include <iostream>
#include <vector>
using namespace std ;

vector<vector<int>> network ;
vector<bool> visited ;
int infected=0 ;

void dfs (int node) {
    visited[node]=true ;
    for (int next : network[node]){
        if (!visited[next]){
            infected++;
            dfs(next);
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    network.resize(n+1);
    visited.resize(n+1, false);
    
    for (int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        network[a].push_back(b);
        network[b].push_back(a);
    }
    
    dfs(1);
    cout<<infected<<'\n';
    return 0;
}