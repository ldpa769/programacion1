// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del estudiante: ING MECATRONICA.
// Fecha creación: 04/11/2026

#include <iostream>
#include <string>
using namespace std;

struct Cuenta {
    string titular;
    int numeroCuenta;
    double saldo;
};

void depositar(Cuenta& c, double cantidad) {
    if (cantidad <= 0) {
        cout << "La cantidad a depositar debe ser positiva." << endl;
        return;
    }
    c.saldo += cantidad;
    cout << "Depósito exitoso de " << cantidad << endl;
}

void retirar(Cuenta& c, double cantidad) {
    if (cantidad <= 0) {
        cout << "La cantidad a retirar debe ser positiva." << endl;
    } else if (cantidad > c.saldo) {
        cout << "Saldo insuficiente. Saldo actual: " << c.saldo << endl;
    } else {
        c.saldo -= cantidad;
        cout << "Retiro exitoso de " << cantidad << endl;
    }
}

int main() {
    Cuenta cuenta = {"Juan Pérez", 123456, 500.0};
    cout << "Titular: " << cuenta.titular << " | Cuenta: " << cuenta.numeroCuenta
         << " | Saldo inicial: " << cuenta.saldo << endl;

    double monto;
    cout << "Monto a depositar: ";
    cin >> monto;
    depositar(cuenta, monto);

    cout << "Monto a retirar: ";
    cin >> monto;
    retirar(cuenta, monto);

    cout << "Saldo final: " << cuenta.saldo << endl;
    return 0;
}
