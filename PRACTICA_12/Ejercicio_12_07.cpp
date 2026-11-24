// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyala Arteaga.
// Fecha creación: 16/11/2026
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

// Calcula el promedio de una línea "Nombre n1 n2 n3 ..." y lo escribe en 'salida'.
// Devuelve false si la línea no tiene calificaciones.
bool procesarLinea(const string& linea, ofstream& salida) {
    istringstream ss(linea);
    string nombre;
    if (!(ss >> nombre)) return false;

    double nota, suma = 0;
    int cantidad = 0;
    while (ss >> nota) {
        suma += nota;
        cantidad++;
    }
    if (cantidad == 0) return false;

    salida << nombre << ' ' << fixed << setprecision(2) << suma / cantidad << '\n';
    return true;
}

// Procesa todo el archivo de calificaciones. Devuelve estudiantes procesados o -1 si falla.
int calcularPromedios(const string& entradaNombre, const string& salidaNombre) {
    ifstream entrada(entradaNombre);
    if (!entrada) return -1;
    ofstream salida(salidaNombre);
    if (!salida) return -1;

    int procesados = 0;
    string linea;
    while (getline(entrada, linea)) {
        if (procesarLinea(linea, salida)) procesados++;
    }
    return procesados;
}

int main() {
    int n = calcularPromedios("calificaciones.txt", "promedios.txt");
    if (n < 0) {
        cout << "No se pudo abrir calificaciones.txt o crear promedios.txt" << endl;
        return 1;
    }
    cout << "Se calcularon " << n << " promedios en promedios.txt" << endl;
    return 0;
}
