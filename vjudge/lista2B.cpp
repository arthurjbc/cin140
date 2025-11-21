#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define el "\n";

void heapifyTopD(std::vector<long long>& a, int k) {
    long long v = a[k];
    while (k > 1 && v < a[k/2]) {
        a[k] = a[k/2]; //duplica
        k = k/2;
    }
    a[k] = v;
}

void heapifyUp(std::vector<long long>& a, int& n, int k) {
    long long v = a[k];
    bool heap = false;

    while ((!heap && 2*k<=n)){
        int j=2*k; // vai ao filho da esquerda

        if ((j<n) && (a[j]>a[j+1])) j++;    // vai ao filho mneor ou fica na esquerda

        if (v<=a[j]) heap=true; 

        else {
            a[k] = a[j];
            k=j;
        }
    }

    a[k] = v;
}


void bottomUp(vector<long long>& a, int& n){
    for (int i = n/2; i>=1; i--){
        int k = i;
        long long v = a[k];
        bool heap = false;

        while ((!heap && 2*k<=n)){
            int j=2*k; // vai ao filho da esquerda

            if ((j<n) && (a[j]>a[j+1])) j++;    // vai ao filho menor ou fica na esquerda

            if (v<=a[j]) heap=true; 

            else {
                a[k] = a[j];
                k=j;
            }
        }

        a[k] = v;
    }
}

int solver(vector<long long>& a, int& n, int& contador, int& positivo){
    int dir = n;
    int cur = positivo;
    bottomUp(a, dir);

    while(dir > 1 && cur>0){
        if (cur>=0 && dir != n){
            contador++;
        } else if (cur<0){
            return contador;
        }
        cur+a[1];
        swap(a[1], a[dir]);
        heapifyUp(a, --dir, 1);
    }
    return contador;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long positivo = 0;
    int contador = 0;
    
    int j = 0;
    vector<long long> a;
    a.push_back(0);
    
    long long ent;
    for (int i = 0; i<n; i++){
        cin >> ent;
        positivo +=ent;
        contador++;

        if (ent < 0) {
            a.push_back(ent); 
            j++;
            heapifyTopD(a, j);
        }

        while (positivo < 0) {
            long long min_negativa = a[1];
            

            positivo -= min_negativa; 
            contador--;
            a[1]=a[j]; 
            a.pop_back();
            j --;         
            if (j > 0) {
                heapifyUp(a, j, 1);
            }
        }
    }
    
    cout << contador << el;
}