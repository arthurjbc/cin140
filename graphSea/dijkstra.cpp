#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <utility>
#include <limits>

using namespace std;

#define forn(i, j ,n) for(int i=j; i<n; i++)
#define el "\n"
#define fio ios_base::sync_with_stdio(false); cin.tie(0);
using ll = long long;
using pii = pair<ll, int>;

void solver(vector<int>& precedente, int s, int e){
    if (s == e){
        cout << s+1 << el;
        return;
    }
    if (precedente[e] == -1){
        cout << -1 << el;
        return;
    }
    if (s == e) {
        cout << s << el;
        return;
    }
    int cur = e;
    stack<int> pilha;
    pilha.push(cur);
    while(cur != s){
        cur = precedente[cur];
        pilha.push(cur);
    }
    int n = pilha.size();
    forn(i, 0, n) {
        cout << pilha.top()+1 << " ";
        pilha.pop();
    }
    cout << el;
}

vector<int> dijkstra(vector<bool>& visited, const vector<vector<pair<int, int>>>& g, const int& n, const int s){
    vector<int> parent(n, -1);
    vector<ll> distance(n, 999);

    distance[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});


    int v, pes, w;
    ll p;
    while(!pq.empty()){
        ll dv = pq.top().first;
        v = pq.top().second;
        pq.pop();

        if (dv > distance[v]) continue;
        if(visited[v]) continue;
        visited[v] = true;
        
        for(const auto& no : g[v]){
            int w = no.first;
            int disvw = no.second;
            if (!visited[w] && distance[w] > distance[v] + disvw){
                distance[w] = distance[v] + disvw;
                parent[w] = v;
                pq.push({distance[w], w});
            }
        }
    }
    return parent;
}

int main(){
    fio
    int n, j; cin >> n >> j;
    vector<bool> visited(n, false);
    vector<vector<pair<int, int>>> g(n);
    
    forn(i, 0, j){
        int a, b ,c; cin >> a >> b >> c;
        g[a-1].push_back({b-1, c});
    }

    vector<int> parent = dijkstra(visited, g, n, 0);

    solver(parent, 0, n-1);


}