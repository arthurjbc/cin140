#include <iostream>
#include <cmath>

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
        int m = floor((l+r)/2);
        if (buscado == a[m]){
            std::cout << "achei" << std::endl;
            return m;
        } else if (buscado < a[m]){
            r = m-1;
        } else {
            l = m+1;
        }
    }
    std::cout << "nao achei" << std::endl;
    return -1;
}


int main(){
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
