// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Carrera del estudiante: Ing. mecatronica
// Fecha creación: 28/08/2026

#include <iostream>

using namespace std;


int contarDigitos(int numero) {
    int contador = 0;

    if (numero == 0) {
        return 1;
    }

    while (numero > 0) {
        numero = numero / 10;
        contador++;
    }

    return contador;
}

int main() {
    int numero;

    cout << "=== CONTADOR DE DIGITOS ===" << endl;
    cout << "Ingrese un numero entero positivo: ";
    cin >> numero;

    if (numero < 0) {
        cout << "Debe ingresar un numero positivo." << endl;
        return 0;
    }

    int cantidad = contarDigitos(numero);

    cout << "El numero " << numero << " tiene " << cantidad << " digitos." << endl;

    return 0;
}
