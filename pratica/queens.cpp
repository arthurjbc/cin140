#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using gr = vector<vector<bool>>;
using vi = vector<int>;
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forn(i, j, n) for(int i = j; i<n; i++)
#define el "\n"

int contador = 0;

bool val(int r, int n, int c, gr& g) {
    for (int j=0; j<c; j++) {
        if (g[r][j]) return false;
    }

    for (int i=r, j=c; i>=0 && j>=0; i--, j--) {
        if (g[i][j]) return false;
    }
    for (int i=r, j=c; i<n && j>=0; i++, j--) {
        if (g[i][j]) return false;
    }
    return true;
}

bool queens(int n, int c, gr& g){
    if (n==c) {contador++;}
    forn(i, 0, n){
        if (val(i, n, c, g)){
            g[i][c] = true;
            if (queens(n, c+1, g)) return true;
            g[i][c]=false;
        }
    }
    return false;
}

int main(){
    fio;
    int n; cin >> n;
    gr g(n, vector<bool> (n, false));
    queens(n, 0, g);
    cout << contador << el;
}