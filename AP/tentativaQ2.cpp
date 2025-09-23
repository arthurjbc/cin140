#include <iostream>
#include <utility>
#include <string>

using namespace std;

void merge (std::pair<int, std::string> a[], int left, int right){
    std::pair<int, std::string>  temp[right+1];

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
        } else if (temp[i1].second == temp[i2].second){
             if (temp[i1].first == temp[i2].first){
                std::pair<int, std::string>  vazio;
                vazio.first = 00;
                vazio.second = "vazxio"
            }  
        } else if (temp[i1].second < temp[i2].second){

        } else {
            a[c] = temp[i2++];
        }
    }
}

void algoritmo(std::pair<int, std::string> a[], int left, int right){
   if (left<right){
    int meio = (left+right)/2;   
    algoritmo(a, left, meio);
    algoritmo(a, meio+1, right);
    merge (a, left, right);
   } 
}   

int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, l, r;
    std::cin >> n;
    std::pair<int, std::string> a[n];
    
    for (int i =0; i<n; i++){
        std::string nome;
        std::cin >> nome;
        int numero;
        std::cin >> numero;
        std::pair<int, std::string> par;
        par.first = numero;
        par.second = nome;
        a[i] = par;
        //std::cout << a[i].first << " - " <<  a[i].second << std::endl;
    }


    l=0;
    r=n-1;

    algoritmo(a, l, r);

    //std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << a[i].second << " " << a[i].first << std::endl;
    }
}
