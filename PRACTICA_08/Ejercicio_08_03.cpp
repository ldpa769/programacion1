// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Algoritmo de Luhn para tarjetas de 16 digitos
bool tarjetaValida(const string& tarjeta) {
    if (tarjeta.length() != 16) return false;
    for (size_t i = 0; i < tarjeta.length(); i++)
        if (!isdigit((unsigned char)tarjeta[i])) return false;

    int suma = 0;
    bool duplicar = false;                 // el ultimo digito NO se duplica
    for (int i = 15; i >= 0; i--) {        // de derecha a izquierda
        int digito = tarjeta[i] - '0';
        if (duplicar) {
            digito *= 2;
            if (digito > 9) digito -= 9;
        }
        suma += digito;
        duplicar = !duplicar;
    }
    return suma % 10 == 0;
}

int main() {
    string tarjeta;
    cout << "Ingrese los 16 digitos de la tarjeta: ";
    getline(cin, tarjeta);

    if (tarjetaValida(tarjeta)) cout << "Tarjeta valida" << endl;
    else cout << "Tarjeta invalida" << endl;
    return 0;
}
