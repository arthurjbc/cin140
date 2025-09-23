#include <iostream>
#include <string>
#include <vector>

using namespace std;

int algoritmo(vector<string> a, int& n, string& buscado){
    int l = 0;
    int r = n-1;
    while (l<=r){
        int m = (l+r)/2;
        if (buscado == a[m]){
            return 1;
        } else if (buscado < a[m]){
            r = m-1;
        } else {
            l = m+1;
        }
    }
    return 0;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<std::string> lista(n);

    for (int i=0; i<n; i++){
        cin >> lista[i];
    }

    int g;
    cin >> g;
    
    int p=0;
    for (int i=0; i<g; i++){
        string guess;
        cin >> guess;
        p += algoritmo(lista, n, guess);
    }
    cout << p << endl;

}
