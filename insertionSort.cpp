#include <iostream>

void entrada(int a[], int n){
    int ent;
    for (int i=0; i<n; i++){
        std::cin >> ent;
        a[i] = ent;
    }
}

void algoritmo(int a[], int n){
    for(int i=1; i<n; i++){
        int v = a[i];
        int j = i-1;
        while (j>=0 and a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
    }    
}


int main(){
    int n;
    while(1){ 
        std::cin >> n;  
        if (n==0){
            break;
        }
        int a[n];
        entrada(a, n);

        algoritmo(a, n);

        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
}

