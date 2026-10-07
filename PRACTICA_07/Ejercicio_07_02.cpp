// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026
// Número de ejercicio: 2

#include <iostream>
#include <vector>
using namespace std;

// Carga los valores fijos en el vector voltios
vector<double> cargarVoltios() {
    vector<double> voltios = {11.95, 16.32, 12.15, 8.22, 15.98, 26.22, 13.54, 6.45, 17.59};
    return voltios;
}

// Muestra el vector en filas de 3 valores
void mostrarVoltios(const vector<double>& voltios) {
    for (size_t i = 0; i < voltios.size(); i++) {
        cout << voltios[i] << "\t";
        if ((i + 1) % 3 == 0) cout << endl;
    }
}

int main() {
    vector<double> voltios = cargarVoltios();
    mostrarVoltios(voltios);
    return 0;
}
