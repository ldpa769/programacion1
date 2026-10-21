// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA..
// Fecha creación: 14/10/2026
// Número de ejercicio: 1

#include <iostream>
#include <string>
using namespace std;

// Ordena los caracteres de la palabra alfabéticamente (inserción)
string ordenarCaracteres(string palabra) {
    for (size_t i = 1; i < palabra.size(); i++) {
        char clave = palabra[i];
        int j = (int)i - 1;
        while (j >= 0 && palabra[j] > clave) {
            palabra[j + 1] = palabra[j];
            j--;
        }
        palabra[j + 1] = clave;
    }
    return palabra;
}

string leerPalabra() {
    string palabra;
    cout << "Ingrese una palabra: ";
    cin >> palabra;
    return palabra;
}

int main() {
    string palabra = leerPalabra();
    cout << "Resultado: " << ordenarCaracteres(palabra) << endl;
    return 0;
}
