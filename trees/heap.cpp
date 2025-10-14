#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define el "\n";

void swap (int& a, int&b){
    int temp = a;
    a=b;
    b=temp;
}

void bottomUp(vector<int>& a, int& n){
    for (int i = n/2; i>=1; i--){
        int k = i;
        int v = a[k];
        bool heap = false;

        while ((!heap && 2*k<=n)){
            int j=2*k; // vai ao filho à esquerda

            if ((j<n) && (a[j]>a[j+1])) j++;    // vai ao filho maior ou fica à esquerda

            if (v<=a[j]) heap=true; // se o maior filho for menor que ele, a heap está satisfeita

            else {
                a[k] = a[j]; // troque o valor dos nós
                k=j;
            }
        }

        a[k] = v;
    }
}

void print(vector<int>& a, int n){
    for (int i = 1; i < n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
}

void heapsort(vector<int>& a, int& n){
    int dir = n;
    while(dir > 0){
        swap(a[1], a[dir]);
        bottomUp(a, --dir);
    }
}


int main(){
    int n;
    cin >> n;
    
    n++;
    vector<int> a(n);

    for (int i=1; i<n; i++){
        cin >> a[i];
    }

    print(a, n);

    bottomUp(a, n);

    print(a, n);

    heapsort(a, n);
    
    print(a, n);
}