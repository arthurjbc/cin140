#include <iostream>

void entrada(int a[], int n){
    int ent;
    for (int i=0; i<n; i++){
        std::cin >> ent;
        a[i] = ent;
    }
}


void merge (int a[], int left, int right){
    int temp[right+1];
    int meio, i1, i2;
    for (int i = left; i<=right; i++){
        temp[i]=a[i];
    }
    meio = (left+right)/2;
    i1 = left;
    i2 = meio+1;
    for (int c=left; c<=right; c++){
        if (i1==meio+1){
            a[c] = temp[i2++];
        } else if (i2 > right) {
            a[c] = temp[i1++];
        } else if (temp[i1]<=temp[i2]){
            a[c] = temp[i1++];
        } else {
            a[c] = temp[i2++];
        }
    }
}

void algoritmo(int a[], int left, int right){
   if (left<right){
    int meio = (left+right)/2;   
    algoritmo(a, left, meio);
    algoritmo(a, meio+1, right);
    merge (a, left, right);
   } 
}   

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    int left;
    int right;
    while(1){ 
        std::cin >> n;  
        if (n==0){
            break;
        }
        int a[n];
        entrada(a, n);
        right = n-1;
        left = 0;

        algoritmo(a, left, right);

        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
}
