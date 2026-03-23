#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    // caso especial
    if (n == 2) {
        cout << "primo";
        return 0;
    }

    // numeros pares
    if (n % 2 == 0) {
        cout << "no primo";
        return 0;
    }

    int limite = sqrt(n);

    // prueba divisores hasta la raiz
    for (int i = 3; i <= limite; i += 2) {
        if (n % i == 0) {
            cout << "no primo";
            return 0;
        }
    }

    cout << "primo";

    return 0;
}