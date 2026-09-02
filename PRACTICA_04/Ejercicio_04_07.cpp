// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Carrera del estudiante: Ing. mecatronica
// Fecha creación: 28/08/2026

#include <iostream>

using namespace std;

double calcularDistanciaMRU(double velocidad, double tiempo) {
    return velocidad * tiempo;
}

int main() {
    double velocidad, tiempo;

    cout << "=== CALCULO DE DISTANCIA (MRU) ===" << endl;
    cout << "Ingrese la velocidad constante (m/s): ";
    cin >> velocidad;
    cout << "Ingrese el tiempo (s): ";
    cin >> tiempo;

    double distancia = calcularDistanciaMRU(velocidad, tiempo);

    cout << "La distancia recorrida es: " << distancia << " metros" << endl;

    return 0;
}
