#include <queue>
#include <vector>
#include <iostream>
#define el "\n"
#define forn(n, i) for(int i=0; i<n; i++)

using namespace std;

int first (vector<vector<int>> g, int v){
    forn(g.size(), i) if (g[v][i] != 0) return i;
    return g.size();
}

int nextN(vector<vector<int>> g, int v, int f){
    for (int i = f+1; i<g.size(); i++) if (g[v][i] != 0) return i;
    return g.size();

}

void bfs(vector<vector<int>> g, int s){
    queue<int> q;
    vector<bool> visited(g.size(), false); 
    
    q.push(s);
    visited[s] = true;
    cout << s << " ";

    while(!q.empty()){
        int v = q.front();
        q.pop();
        
        int w = first(g, v);
        
        while(w < g.size()){
            if (visited[w] == false){
                visited[w] = true;
                cout << w << " ";
                q.push(w);
            }
            w = nextN(g, v, w);
        }
    }
    cout << el;
}

int main(){    
    int n = 5;
    vector<vector<int>> graph(n, vector<int>(n, 0));

    graph[0][1] = 1;
    graph[0][2] = 1;

    graph[1][0] = 1;
    graph[1][3] = 1;
    graph[1][4] = 1;

    graph[2][0] = 1;

    graph[3][1] = 1;

    graph[4][1] = 1;

    bfs(graph, 0);

    return 0;
}