#include <iostream>

void entrada(int a[], int n){
    int ent;
    for (int i=0; i<n; i++){
        std::cin >> ent;
        a[i] = ent;
    }
}


void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int left, int right){
    int pivot, index, pointerEnd;
    pivot = a[left];
    index = left;
    pointerEnd = right+1;   

    do {
        
        do {
            index++;
        } while (a[index]<pivot && index < right);

        do {
            pointerEnd--;
        } while (a[pointerEnd] > pivot);
        
        swap(&a[index], &a[pointerEnd]);

    } while (index < pointerEnd);

    swap(&a[index], &a[pointerEnd]);
    swap(&a[left], &a[pointerEnd]);
    return pointerEnd;
}

void algoritmo(int a[], int left, int right){
    int s;
    if (left<right){
        s=partition(a, left, right);
        algoritmo(a, left, s-1);
        algoritmo(a, s+1, right);
    }
}


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, left ,right;
    while(1){ 
        std::cin >> n;  
        if (n==0){
            break;
        }
        int a[n];
        entrada(a, n);

        left = 0;
        right = n-1;

        algoritmo(a, left, right);

        for (int i = 0; i < n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
}
