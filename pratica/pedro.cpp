#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> a, int& n, int& buscado){
    int l = 0;
    int r = n-1;
    while(l<=r){
        int m = (r+l)/2;
        if (buscado == a[m]){
            return m;
        } else if (buscado < a[m]){
            r = m-1;
        } else {
            l = m+1;
        }
    }

    int mi = abs(a[l]);
    int max = abs(a[r]);

    int ret = min(mi, max);
    if (ret == mi){
        return l;
    } else {
        return r;
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector <int> a(n);

    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int busca;
    cin >> busca;

    int nBusca;
    for (int i = 0; i<busca ; i++){
        cin >> nBusca;
        cout << a[binarySearch(a, n, nBusca)] << endl;
    }

}
