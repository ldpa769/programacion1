// Materia: Programación I, Paralelo 4
// Autor: Luis Puyal
// Fecha creación: 07/10/2026
// Número de ejercicio: 4

#include <iostream>
#include <vector>
#include <random>
using namespace std;

typedef vector<vector<int>> Matriz;

Matriz generarMatriz(int n, int m, int minimo, int maximo) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(minimo, maximo);
    Matriz mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = dist(gen);
        }
    }
    return mat;
}

void mostrarMatriz(const Matriz &mat) {
    for (const auto &fila : mat) {
        for (int x : fila) {
            cout << x << "\t";
        }
        cout << endl;
    }
}

// Busca puntos de silla: menor de su fila y mayor de su columna.
// Devuelve true si encontro al menos uno (e imprime todos).
bool buscarPuntoSilla(const Matriz &mat) {
    int n = mat.size();
    int m = mat[0].size();
    bool encontrado = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int valor = mat[i][j];

            bool menorEnFila = true;
            for (int k = 0; k < m; k++) {
                if (mat[i][k] < valor) {
                    menorEnFila = false;
                    break;
                }
            }

            bool mayorEnColumna = true;
            for (int k = 0; k < n; k++) {
                if (mat[k][j] > valor) {
                    mayorEnColumna = false;
                    break;
                }
            }

            if (menorEnFila && mayorEnColumna) {
                cout << "Punto de silla: " << valor << " en (fila " << i + 1
                     << ", columna " << j + 1 << ")" << endl;
                encontrado = true;
            }
        }
    }
    return encontrado;
}

int main() {
    int n, m;
    cout << "Numero de filas (N): ";
    cin >> n;
    cout << "Numero de columnas (M): ";
    cin >> m;

    if (n <= 0 || m <= 0) {
        cout << "Dimensiones invalidas." << endl;
        return 1;
    }

    Matriz mat = generarMatriz(n, m, 1, 10);

    cout << "\nMatriz generada:" << endl;
    mostrarMatriz(mat);
    cout << endl;

    if (!buscarPuntoSilla(mat)) {
        cout << "No se encontro ningun punto de silla." << endl;
    }

    return 0;
}
