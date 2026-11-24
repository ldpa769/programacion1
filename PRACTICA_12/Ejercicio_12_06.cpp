// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyala Arteaga.
// Fecha creación: 16/11/2026
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Lee temperaturas.txt y escribe en altas_temperaturas.txt las ciudades
// cuya temperatura es mayor a 'limite'. Devuelve la cantidad filtrada, o -1 si falla.
int filtrarTemperaturas(const string& entradaNombre, const string& salidaNombre, double limite) {
    ifstream entrada(entradaNombre);
    if (!entrada) return -1;
    ofstream salida(salidaNombre);
    if (!salida) return -1;

    int cantidad = 0;
    string linea;
    while (getline(entrada, linea)) {
        size_t pos = linea.rfind(' ');
        if (pos == string::npos) continue;
        string ciudad = linea.substr(0, pos);
        double temperatura;
        try {
            temperatura = stod(linea.substr(pos + 1));
        } catch (...) {
            continue;
        }
        if (temperatura > limite) {
            salida << ciudad << ' ' << temperatura << '\n';
            cantidad++;
        }
    }
    return cantidad;
}

int main() {
    double n;
    cout << "Ingrese la temperatura límite N (°C): ";
    if (!(cin >> n)) {
        cout << "Valor inválido." << endl;
        return 1;
    }

    int cantidad = filtrarTemperaturas("temperaturas.txt", "altas_temperaturas.txt", n);
    if (cantidad < 0) {
        cout << "No se pudo abrir temperaturas.txt o crear altas_temperaturas.txt" << endl;
        return 1;
    }
    cout << cantidad << " ciudad(es) superan " << n << "°C. Guardadas en altas_temperaturas.txt" << endl;
    return 0;
}
