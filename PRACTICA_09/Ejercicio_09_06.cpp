// Materia: Programación I, Paralelo 4
// Autor: Luis Puyal
// Fecha creación: 07/10/2026
// Número de ejercicio: 6

#include <iostream>
#include <random>
using namespace std;

const int SEMANAS = 4;
const int DIAS = 7;

void llenarTemperaturas(int temp[SEMANAS][DIAS]) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(5, 35);
    for (int i = 0; i < SEMANAS; i++) {
        for (int j = 0; j < DIAS; j++) {
            temp[i][j] = dist(gen);
        }
    }
}

void mostrarTemperaturas(const int temp[SEMANAS][DIAS]) {
    cout << "          ";
    for (int j = 0; j < DIAS; j++) {
        cout << "Dia " << j + 1 << "\t";
    }
    cout << endl;
    for (int i = 0; i < SEMANAS; i++) {
        cout << "Semana " << i + 1 << ": ";
        for (int j = 0; j < DIAS; j++) {
            cout << temp[i][j] << "C\t";
        }
        cout << endl;
    }
}

// Devuelve la temperatura mas alta y su semana y dia por referencia
int temperaturaMasAlta(const int temp[SEMANAS][DIAS], int &semana, int &dia) {
    int mayor = temp[0][0];
    semana = 0;
    dia = 0;
    for (int i = 0; i < SEMANAS; i++) {
        for (int j = 0; j < DIAS; j++) {
            if (temp[i][j] > mayor) {
                mayor = temp[i][j];
                semana = i;
                dia = j;
            }
        }
    }
    return mayor;
}

void promedioPorSemana(const int temp[SEMANAS][DIAS]) {
    for (int i = 0; i < SEMANAS; i++) {
        int suma = 0;
        for (int j = 0; j < DIAS; j++) {
            suma += temp[i][j];
        }
        cout << "Promedio semana " << i + 1 << ": " << (double)suma / DIAS << " C" << endl;
    }
}

int contarMayoresA(const int temp[SEMANAS][DIAS], int limite) {
    int contador = 0;
    for (int i = 0; i < SEMANAS; i++) {
        for (int j = 0; j < DIAS; j++) {
            if (temp[i][j] > limite) {
                contador++;
            }
        }
    }
    return contador;
}

int main() {
    int temperaturas[SEMANAS][DIAS];

    llenarTemperaturas(temperaturas);

    cout << "Temperaturas registradas:" << endl;
    mostrarTemperaturas(temperaturas);

    int semana, dia;
    int mayor = temperaturaMasAlta(temperaturas, semana, dia);
    cout << "\nTemperatura mas alta del mes: " << mayor << " C (semana "
         << semana + 1 << ", dia " << dia + 1 << ")" << endl;

    cout << endl;
    promedioPorSemana(temperaturas);

    cout << "\nDias con temperatura mayor a 30 C: "
         << contarMayoresA(temperaturas, 30) << endl;

    return 0;
}
