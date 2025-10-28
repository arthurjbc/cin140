#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define el "\n";

#define forn(i, j, n) for(int i = j; i<n; i++)

#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr)

int first (vector<vector<int>> g, int v){
    forn(i, 0, g.size()) if (g[v][i] != 0) return i;
    return g.size();
}

int nextN(vector<vector<int>> g, int v, int f){
    for (int i = f+1; i<g.size(); i++) if (g[v][i] != 0) return i;
    return g.size();

}

void bfs(vector<vector<int>>& g, int s, vector<bool>& visited){
    queue<int> q;
    
    q.push(s);
    visited[s] = true;
    //cout << s << " ";

    while(!q.empty()){
        int v = q.front();
        q.pop();
        
        int w = first(g, v);
        
        while(w < g.size()){
            if (visited[w] == false){
                visited[w] = true;
                //cout << w << " ";
                q.push(w);
            }
            w = nextN(g, v, w);
        }
    }
    //cout << el;
}

vector<vector<int>> construirGrafo(int v, int a){
    vector<vector<int>> g(v, vector<int>(v, 0));
    forn(i, 0, a){
        int h, j; cin >> h >> j;
        g[h][j] = 1;
        g[j][h] = 1;
    }
    return g;
}

int graphTrans(vector<vector<int>>& g, int n, vector<bool>& visited){
    int count = 0;
    forn(i, 0, n){
        if(visited[i] == false){
            bfs(g, i, visited);
            count++;
        }
    }
    return count;
}

int main(){
    fio;
    int n; cin >> n;
    forn(i, 0, n){
        int v, a; cin >> v >> a;
        vector<vector<int>> g = construirGrafo(v, a);

        vector<bool> visited (v, false);
        cout << graphTrans(g, v, visited) << el;
    }
}