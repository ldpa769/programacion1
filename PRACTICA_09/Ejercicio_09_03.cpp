// Materia: Programación I, Paralelo 4
// Autor: Luis Puyal
// Fecha creación: 07/10/2026
// Número de ejercicio: 3

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matriz;

// Cada fila empieza 2 unidades mas arriba que la anterior
// y cada columna suma 1: valor = 2*i + j + 1
Matriz generarMatriz(int n) {
    Matriz m(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = 2 * i + j + 1;
        }
    }
    return m;
}

void mostrarMatriz(const Matriz &m) {
    for (const auto &fila : m) {
        for (int x : fila) {
            cout << x << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Orden de la matriz (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "n debe ser mayor a 0." << endl;
        return 1;
    }

    Matriz m = generarMatriz(n);

    cout << "\nMatriz generada:" << endl;
    mostrarMatriz(m);

    return 0;
}
