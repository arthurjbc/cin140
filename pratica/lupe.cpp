#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<int> numeros(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numeros[i];
    }

    std::sort(numeros.begin(), numeros.end());

    int vencedor = -1;

    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && numeros[j] == numeros[i]) {
            j++;
        }

        if (j - i == 1) {
            vencedor = numeros[i];
            break;
        }

        i = j;
    }

    std::cout << vencedor << std::endl;

}