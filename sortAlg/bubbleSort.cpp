#include <iostream>

void entrada(int a[], int n){
    int ent;
    for (int i=0; i<n; i++){
        std::cin >> ent;
        a[i] = ent;
    }
}

void algoritmo(int a[], int n){

    for (int i = 0; i < n; i++){
        for (int j =0; j < n-1-i; j++){
            if (a[j+1]<a[j]){
                int temp = a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
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
