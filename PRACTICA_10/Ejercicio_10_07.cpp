// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA..
// Fecha creación: 14/10/2026
// Número de ejercicio: 1

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

const int ALUMNOS = 5;
const int NOTAS = 3;

// Lee nombres y 3 notas parciales (0 a 100) de cada alumno
void leerDatos(vector<string>& nombres, vector<vector<int>>& notas) {
    for (int i = 0; i < ALUMNOS; i++) {
        string nombre;
        cout << "Alumno " << i + 1 << " (nombre): ";
        cin >> nombre;
        nombres.push_back(nombre);
        for (int j = 0; j < NOTAS; j++) {
            int nota;
            do {
                cout << "  Nota " << j + 1 << " (0-100): ";
                cin >> nota;
            } while (nota < 0 || nota > 100);
            notas[i][j] = nota;
        }
    }
}

// Calcula el promedio de cada alumno a partir de la matriz
void calcularPromedios(const vector<vector<int>>& notas, vector<float>& promedios) {
    promedios.clear();
    for (int i = 0; i < ALUMNOS; i++) {
        int suma = 0;
        for (int j = 0; j < NOTAS; j++) suma += notas[i][j];
        promedios.push_back((float)suma / NOTAS);
    }
}

// Ordena los nombres alfabéticamente (selección) y mueve en paralelo
// la fila de notas y el promedio para mantener todo sincronizado
void ordenarPorNombre(vector<string>& nombres, vector<vector<int>>& notas,
                      vector<float>& promedios) {
    for (int i = 0; i < ALUMNOS - 1; i++) {
        int posMin = i;
        for (int j = i + 1; j < ALUMNOS; j++) {
            if (nombres[j] < nombres[posMin]) posMin = j;
        }
        if (posMin != i) {
            string auxN = nombres[i];
            nombres[i] = nombres[posMin];
            nombres[posMin] = auxN;

            vector<int> auxFila = notas[i];
            notas[i] = notas[posMin];
            notas[posMin] = auxFila;

            float auxP = promedios[i];
            promedios[i] = promedios[posMin];
            promedios[posMin] = auxP;
        }
    }
}

// Imprime el boletín: Nombre | Nota 1 | Nota 2 | Nota 3 | Promedio
void imprimirBoletin(const vector<string>& nombres, const vector<vector<int>>& notas,
                     const vector<float>& promedios) {
    cout << "\n" << left << setw(12) << "Nombre" << "| "
         << setw(7) << "Nota 1" << "| " << setw(7) << "Nota 2" << "| "
         << setw(7) << "Nota 3" << "| Promedio" << endl;
    cout << string(54, '-') << endl;
    for (int i = 0; i < ALUMNOS; i++) {
        cout << left << setw(12) << nombres[i] << "| ";
        for (int j = 0; j < NOTAS; j++) {
            cout << setw(7) << notas[i][j] << "| ";
        }
        cout << fixed << setprecision(2) << promedios[i] << endl;
    }
}

int main() {
    vector<string> nombres;
    vector<vector<int>> notas(ALUMNOS, vector<int>(NOTAS, 0));
    vector<float> promedios;

    leerDatos(nombres, notas);
    calcularPromedios(notas, promedios);
    ordenarPorNombre(nombres, notas, promedios);
    imprimirBoletin(nombres, notas, promedios);
    return 0;
}
