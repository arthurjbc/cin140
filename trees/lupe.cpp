#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

#define el "\n";

void print(vector<int>& a, int n){
    for (int i = 1; i <= n; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << el;
}

void swap (int& a, int&b){
    int temp = a;
    a=b;
    b=temp;
}

void siftDownMin(std::vector<int>& a, int n, int k) {
    int v = a[k]; 
    bool heap = false;

    while (!heap && 2 * k<=n) {
        int j = 2 * k; 

        if (j < n && a[j] > a[j + 1]) {
            j++; 
        }

        if (v <= a[j]) heap = true;

        else {
            a[k] = a[j];
            k = j;
        }
    }
    a[k] = v;
}

void bottomUp(vector<int>& a, int& n){
    for (int i = n/2; i>=1; i--){
        int k = i;
        int v = a[k];
        bool heap = false;

        while ((!heap && 2*k<=n)){
            int j=2*k; // vai ao filho da esquerda

            if ((j<n) && (a[j]>a[j+1])) j++;    // vai ao filho maior ou fica na esquerda

            if (v<=a[j]) heap=true; 

            else {
                a[k] = a[j];
                k=j;
            }
        }

        a[k] = v;
    }
}

void heapsort(vector<int>& a, int& n){
    int dir = n;
    bottomUp(a, n);
    while(dir > 1){
        swap(a[1], a[dir]);
        //print(a, n);
        cout << a[dir] << el;
        siftDownMin(a, --dir, 1);
    }
}

int SortnCheck(vector<int>& a, int n){
    int dir = n;
    
    bottomUp(a, n);
    
    int min = a[1];
    int count =1;
    swap(a[1], a[dir]);
    siftDownMin(a, --dir, 1);


    while(dir > 0){
        if (a[1] == min){
            count++;
        } else {
            if (count == 1){
                return min;
            }
            min = a[1];
            count = 1;
        }
        if (dir > 1) swap(a[1], a[dir]);
        siftDownMin(a, --dir, 1);
    }
    if (count == 1) return min;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    
    n;
    vector<int> a(n+1);

    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    cout << SortnCheck(a, n) << el;
    print(a, n);
}