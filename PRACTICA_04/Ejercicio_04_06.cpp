// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Carrera del estudiante: Ing. mecatronica
// Fecha creación: 28/08/2026

#include <iostream>

using namespace std;

long sumatoriaNaturales(int n) {
    long suma = 0;

    for (int i = 1; i <= n; i++) {
        suma += i;
    }

    return suma;
}

int main() {
    int n;

    cout << "=== SUMATORIA DE NUMEROS NATURALES ===" << endl;
    cout << "Ingrese un numero entero positivo N: ";
    cin >> n;

    if (n <= 0) {
        cout << "Debe ingresar un numero positivo." << endl;
        return 0;
    }

    long suma = sumatoriaNaturales(n);

    cout << "La suma de 1 hasta " << n << " es: " << suma << endl;

    return 0;
}
