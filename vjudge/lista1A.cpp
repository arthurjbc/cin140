#include <iostream>

using namespace std;


int binSearch(int a[], const int& n, const int& buscado){
    int l = 0;
    int r = n-1;
    while (l<=r){
        int m = (l+r)/2;
        if (buscado == a[m]){
            std::cout << m << std::endl;
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

void swap (int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(int a[], const int& left, const int& right){
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
        
        swap(a[index], a[pointerEnd]);

    } while (index < pointerEnd);

    swap(a[index], a[pointerEnd]);
    swap(a[left], a[pointerEnd]);
    return pointerEnd;
}

void algoritmo(int a[], const int& left, const int& right){
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
    int n, left, right, mi, q;
    std::cin >> n;
    int a[n];
    int ent;
    for (int i=0; i<n; i++){
        std::cin >> ent;
        a[i] = ent;
    }
    right = n-1;
    left = 0;

    algoritmo(a, left, right);
    std::cin >> q;
    
    for (int i = 0; i<q; i++){
        std::cin >> mi;
        for (int j=n-1; j>=0; j--){
            if (a[j]<=mi){
                cout << j+1 << endl;
                break;
            } else if (j==0){
                cout << 0 << endl;
            }
        }
    }
}
