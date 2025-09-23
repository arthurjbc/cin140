#include <iostream>

using namespace std;

void entrada(int a[], int n){
    int ent;
    for (int i=0; i<n; i++){
        std::cin >> ent;
        a[i] = ent;
    }
}

int algoritmo(int a[], int n, int buscado){
    int l = 0;
    int r = n-1;
    while (l<=r){
        int m = (l+r)/2;
        if (buscado == a[m]){
            std::cout << m << std::endl;
            cout << n-m-1 << endl;
            return m;
        } else if (buscado < a[m]){
            r = m-1;
        } else {
            l = m+1;
        }
    }
    std::cout << -1 << std::endl;
    return -1;
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    int buscado;
    while(1){ 
        std::cin >> n;  
        if (n==0){
            break;
        }
        std::cin >> buscado;  
        int a[n];
        entrada(a, n);

        int m = algoritmo(a, n, buscado);

        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
}
