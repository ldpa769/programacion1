// Materia: Programación I, Paralelo 4
// Autor: Luis Puyal
// Fecha creación: 07/10/2026
// Número de ejercicio: 2

#include <iostream>
#include <vector>
#include <random>
using namespace std;

typedef vector<vector<int>> Matriz;

Matriz generarMatriz(int n, int a, int b) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(a, b);
    Matriz m(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = dist(gen);
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

long long sumaUltimaColumna(const Matriz &m) {
    int n = m.size();
    long long suma = 0;
    for (int i = 0; i < n; i++) {
        suma += m[i][n - 1];
    }
    return suma;
}

long long productoUltimaFila(const Matriz &m) {
    int n = m.size();
    long long prod = 1;
    for (int j = 0; j < n; j++) {
        prod *= m[n - 1][j];
    }
    return prod;
}

// Devuelve el mayor valor y su posicion por referencia
int mayorValor(const Matriz &m, int &fila, int &columna) {
    int n = m.size();
    int mayor = m[0][0];
    fila = 0;
    columna = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] > mayor) {
                mayor = m[i][j];
                fila = i;
                columna = j;
            }
        }
    }
    return mayor;
}

double promedio(const Matriz &m) {
    int n = m.size();
    long long suma = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            suma += m[i][j];
        }
    }
    return (double)suma / (n * n);
}

int main() {
    int n, a, b;
    cout << "Orden de la matriz (N): ";
    cin >> n;
    cout << "Valor minimo (A): ";
    cin >> a;
    cout << "Valor maximo (B): ";
    cin >> b;

    if (n <= 0) {
        cout << "N debe ser mayor a 0." << endl;
        return 1;
    }
    if (a > b) {
        swap(a, b);
    }

    Matriz m = generarMatriz(n, a, b);

    cout << "\nMatriz generada:" << endl;
    mostrarMatriz(m);

    int f, c;
    int mayor = mayorValor(m, f, c);

    cout << "\nSuma de la ultima columna: " << sumaUltimaColumna(m) << endl;
    cout << "Producto de la ultima fila: " << productoUltimaFila(m) << endl;
    cout << "Mayor valor: " << mayor << " en la posicion (fila " << f + 1
         << ", columna " << c + 1 << ")" << endl;
    cout << "Promedio: " << promedio(m) << endl;

    return 0;
}
