// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Carrera del estudiante: Ing. mecatronica
// Fecha creación: 28/08/2026

#include <iostream>

using namespace std;

bool esPar(int numero) {
    return (numero % 2 == 0);
}

int main() {
    int numero;

    cout << "=== VERIFICACION DE PARIDAD ===" << endl;
    cout << "Ingrese un numero entero: ";
    cin >> numero;

    if (esPar(numero)) {
        cout << "El numero " << numero << " es PAR." << endl;
    } else {
        cout << "El numero " << numero << " es IMPAR." << endl;
    }

    return 0;
}
