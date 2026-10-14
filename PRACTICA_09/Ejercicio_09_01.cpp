// Materia: Programación I, Paralelo 4
// Autor: Luis Puyal
// Fecha creación: 07/10/2026
// Número de ejercicio: 1

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matriz;

Matriz leerMatriz(int filas, int columnas) {
    Matriz m(filas, vector<int>(columnas));
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> m[i][j];
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

// Intercambia la primera fila con la ultima
void cambiarPrimeraConUltima(Matriz &m) {
    int n = m.size();
    if (n > 1) {
        swap(m[0], m[n - 1]);
    }
}

int main() {
    int filas, columnas;
    cout << "Numero de filas: ";
    cin >> filas;
    cout << "Numero de columnas: ";
    cin >> columnas;

    if (filas <= 0 || columnas <= 0) {
        cout << "Dimensiones invalidas." << endl;
        return 1;
    }

    Matriz m = leerMatriz(filas, columnas);

    cout << "\nMatriz original:" << endl;
    mostrarMatriz(m);

    cambiarPrimeraConUltima(m);

    cout << "\nMatriz con la fila 1 cambiada por la fila " << filas << ":" << endl;
    mostrarMatriz(m);

    return 0;
}
