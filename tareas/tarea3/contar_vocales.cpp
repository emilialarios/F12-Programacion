#include <iostream>
#include <string>
using namespace std;

int main() {
    string texto;
    getline(cin, texto);

    int contador = 0;

    // recorre la cadena y cuenta vocales
    for (int i = 0; i < texto.length(); i++) {
        char c = texto[i];

        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            contador++;
        }
    }

    cout << contador;

    return 0;
}