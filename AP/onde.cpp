#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

#define el "\n";

#define forn(i, j, n) for(int i = j; i<n; i++)

#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr)

int first (vector<vector<int>> g, int& v){
    forn(i, 0, g.size()) if (g[v][i] != 0) return i;
    return g.size();
}

int nextN(vector<vector<int>> g, int& v, int& f){
    for (int i = f+1; i<g.size(); i++) if (g[v][i] != 0) return i;
    return g.size();

}

int bfs(vector<vector<int>>& g, int& s, vector<bool>& visited, vector<int>& precedent, int& p){
    queue<int> q;
    
    precedent[s] = 0;
    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        
        int w = first(g, v);
        
        while(w < g.size()){
            if (visited[w] == false){
                visited[w] = true;
                precedent[w] = v;
                q.push(w);
                if (w == p) return 1;
            }
            w = nextN(g, v, w);
        }
    }
    return -1;
}

vector<vector<int>> construirGrafo(int& v, int& a){
    vector<vector<int>> g(v, vector<int>(v, 0));
    forn(i, 0, a){
        int h, j; cin >> h >> j;
        g[h][j] = 1;
        g[j][h] = 1;
    }
    return g;
}

void recon (vector<int>& precedente, int& e, int& s){
    int cur = e;
    stack<int> pilha;
    pilha.push(cur);
    while(cur != s){
        cur = precedente[cur];
        pilha.push(cur);
    }
    int n = pilha.size();
    forn(i, 0, n) {
        cout << pilha.top() << " ";
        pilha.pop();
    }
    cout << el;
}

int main(){
    fio;
    int n; cin >> n;
    forn(i, 0, n){
        cout << "Caso " << n << el;
        int v, a; cin >> v >> a;
        vector<vector<int>> g = construirGrafo(v, a);
        
        int p; cin >> p;
        forn(j, 0, p){
            vector<bool> visited (v, false);
            vector<int> precedent (v, -1);
            int s, e; cin >> s >> e;
            if (bfs(g, s, visited, precedent, e) == -1){
                cout << -1 << el;
            } else recon(precedent, e, s);
        }
    }
}