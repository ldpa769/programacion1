// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Carrera del estudiante: Ing. mecatronica
// Fecha creación: 28/08/2026

#include <iostream>

using namespace std;

double convertirBsADolares(double montoBs, double tipoCambio) {
    return montoBs / tipoCambio;
}

int main() {
    double montoBs, tipoCambioOficial, tipoCambioParalelo;

    cout << "=== CONVERSION DE DIVISAS (Bs a USD) ===" << endl;
    cout << "Ingrese el monto en bolivianos: ";
    cin >> montoBs;
    cout << "Ingrese el tipo de cambio oficial: ";
    cin >> tipoCambioOficial;
    cout << "Ingrese el tipo de cambio paralelo: ";
    cin >> tipoCambioParalelo;

    double montoOficial = convertirBsADolares(montoBs, tipoCambioOficial);
    double montoParalelo = convertirBsADolares(montoBs, tipoCambioParalelo);

    cout << "Monto en USD (tipo de cambio oficial): " << montoOficial << endl;
    cout << "Monto en USD (tipo de cambio paralelo): " << montoParalelo << endl;

    return 0;
}
