#include <iostream>

void entrada(int a[], int n){
    int ent;
    for (int i=0; i<n; i++){
        std::cin >> ent;
        a[i] = ent;
    }
}

void algoritmo(int a[], int n){
        int min;
        for (int i = 0; i < n; i++){
            min = i;
            for (int j = i+1; j < n; j++){
                if (a[j] < a[min]){
                    min = j;
                }
            }
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
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
