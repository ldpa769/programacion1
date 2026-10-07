// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026
// Número de ejercicio: 7

#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100;

// Lee numeros hasta llenar MAX elementos o hasta que se ingrese un negativo.
// Devuelve la cantidad de elementos realmente introducidos.
int llenarVector(int v[]) {
    int cantidad = 0;
    int numero;
    while (cantidad < MAX) {
        cout << "Numero [" << cantidad << "] (negativo para terminar): ";
        cin >> numero;
        if (numero < 0) break;
        v[cantidad] = numero;
        cantidad++;
    }
    return cantidad;
}

// Imprime solo los elementos introducidos
void imprimirVector(const int v[], int cantidad) {
    cout << "\nElementos introducidos (" << cantidad << "):\n";
    for (int i = 0; i < cantidad; i++) cout << v[i] << " ";
    cout << endl;
}

int main() {
    int numeros[MAX];
    int cantidad = llenarVector(numeros);
    imprimirVector(numeros, cantidad);
    return 0;
}
