#include <iostream>
using namespace std;

void bubbleSort(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool intercambiado = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (lista[j] > lista[j + 1]) {
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
                intercambiado = true;
            }
        }
        if (!intercambiado) break;
    }
}

void selectionSort(int lista[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = lista[i];
            lista[i] = lista[min_idx];
            lista[min_idx] = temp;
        }
    }
}

void merge(int lista[], int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    int izq[n1], der[n2];

    for (int i = 0; i < n1; i++)
        izq[i] = lista[inicio + i];

    for (int j = 0; j < n2; j++)
        der[j] = lista[medio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (izq[i] <= der[j]) {
            lista[k++] = izq[i++];
        } else {
            lista[k++] = der[j++];
        }
    }

    while (i < n1) {
        lista[k++] = izq[i++];
    }

    while (j < n2) {
        lista[k++] = der[j++];
    }
}

void mergeSort(int lista[], int inicio, int fin) {
    if (inicio >= fin) return;

    int medio = inicio + (fin - inicio) / 2;

    mergeSort(lista, inicio, medio);
    mergeSort(lista, medio + 1, fin);

    merge(lista, inicio, medio, fin);
}

int main() {
    string algoritmo;
    int n;

    cin >> algoritmo;
    cin >> n;

    int lista[n];

    for (int i = 0; i < n; i++) {
        cin >> lista[i];
    }

    if (algoritmo == "burbuja") {
        bubbleSort(lista, n);
    } else if (algoritmo == "seleccion") {
        selectionSort(lista, n);
    } else if (algoritmo == "mergesort") {
        mergeSort(lista, 0, n - 1);
    }

    for (int i = 0; i < n; i++) {
        cout << lista[i];
        if (i < n - 1) cout << " ";
    }

    cout << endl;

    return 0;
}