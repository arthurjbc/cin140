#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

#define el "\n"
#define fio ios_base::sync_with_stdio(false); cin.tie(0);
#define forn(i, j ,n) for(int i=j; i<n; i++)
using ll = long long;
using pii = pair<ll, int>;

int findD(int v, vector<int>& parent) {
    if (v == parent[v]) return v;
    return parent[v] = findD(parent[v], parent);
}
bool uniond(int a, int b, vector<int>& parent, vector<int>& ranking) {
    a = findD(a, parent);
    b = findD(b, parent);

    if (a != b) {
        if (ranking[a] < ranking[b])
            swap(a, b);
        parent[b] = a;
        if (ranking[a] == ranking[b])
            ranking[a]++;
        return true;
    }
    return false; 
}

void solve() {
    int n, m; cin >> n >> m;

    vector<vector<int>> g;
    forn(k, 0, m) {
        int i, j, p; cin >> i >> j >> p;
        g.push_back({p, i, j});
    }

    sort(g.begin(), g.end());
    vector<int> parent(n);
    forn(i, 0, n) parent[i] = i;
    vector<int> ranking(n, 0);


    ll mstP = 0; 
    int edgecnt = 0;

    for(const auto& w : g){

        int c = w[0];
        int u = w[1];
        int v = w[2];
        
        if (findD(u, parent) != findD(v, parent)) {
            mstP += c;
            uniond(u, v, parent, ranking);
            edgecnt++;
            n--;
        }
    }

    cout << mstP << el;
}

int main() {
    fio 
    solve();
}