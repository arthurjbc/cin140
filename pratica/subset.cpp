#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using gr = vector<vector<bool>>;
using vi = vector<int>;
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define forn(i, j, n) for(int i = j; i<n; i++)
#define el "\n"

bool subset (vi& a, int n, int soma, int goal, int resto, int i){
    if (soma == goal) return true;
    if (soma+a[i] > goal) return false;
    if (soma+resto < goal) return false;
    if (subset(a, n, soma+a[i], goal, resto-a[i], i+1)) return true; 
    else if (subset(a, n, soma, goal, resto, i+1)) return true;
    else return false;

}

int main(){
    fio;
    int t; cin >> t;
    forn(i, 0, t){
        int n, k; cin >> n >> k;
        vi a(n);
        int sum = 0;
        forn(i, 0,n) {cin >> a[i]; sum+=a[i];}
        sort(a.begin(), a.end());
    
    
        if (subset(a, n, 0, k, sum, 0)) cout << 1 << el;
        else cout << 0 << el;
    }
}
