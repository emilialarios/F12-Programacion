#include <iostream>
using namespace std;

int busqueda_dos_en_dos(int arr[], int n, int objetivo) {
    int i = 0;

    // avanza de 2 en 2
    while (i < n && arr[i] < objetivo) {
        i = i + 2;
    }

    // retrocede una posicion
    if (i > 0) {
        i = i - 1;
    }

    // revisa los posibles candidatos
    for (int j = i; j <= i + 1 && j < n; j++) {
        if (arr[j] == objetivo) {
            return j;
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    int arr[100000];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int objetivo;
    cin >> objetivo;

    cout << busqueda_dos_en_dos(arr, n, objetivo);

    return 0;
}