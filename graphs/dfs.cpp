#include <iostream>
#include <vector>
#define el "\n"

using namespace std;

#define forn(i, n) for(int i=0; i<n; i++)

int first(vector<vector<int>> g, int v){
    forn(i, g.size()) if (g[v][i] != 0) return i;
    return g.size();
}

int nextN(vector<vector<int>> g, int v, int w){
    for (int i=w+1; i<g.size(); i++) if (g[v][i] != 0) return i;
    return g.size();
}

void dfs(vector<vector<int>> v, int k, vector<bool> visited){
    visited[k] = true;
    cout << k << " ";
    int w = first(v, k);
    while(w < v.size()){
        if(visited[w] == false) dfs(v, w, visited);
        w = nextN(v, k, w);
    }
}   

int main(){
    int n = 5;
    vector<bool> visited(n, false);
    vector<vector<int>> graph(n, vector<int>(n, 0));

    graph[0][1] = 1;
    graph[0][2] = 1;

    graph[1][0] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;

    graph[2][0] = 1;

    graph[3][1] = 1;

    graph[4][1] = 1;

    dfs(graph, 0, visited);
    cout << el;
}