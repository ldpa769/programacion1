// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del estudiante: ING MECATRONICA.
// Fecha creación: 04/11/2026


#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Paquete {
    string codigoRastreo;
    char direccion[50];
    double pesoKg;
    char estado[20];
};

Paquete leerPaquete() {
    Paquete p;
    cout << "Código de rastreo: ";
    getline(cin, p.codigoRastreo);
    cout << "Dirección (máx. 49 caracteres): ";
    cin.getline(p.direccion, 50);
    cout << "Peso (kg): ";
    cin >> p.pesoKg;
    strcpy(p.estado, "En Tránsito");
    return p;
}

void entregarPaquete(Paquete& p) {
    strcpy(p.estado, "Entregado");
    cout << "\n======= RECIBO =======" << endl;
    cout << "Código:    " << p.codigoRastreo << endl;
    cout << "Dirección: " << p.direccion << endl;
    cout << "Peso:      " << p.pesoKg << " kg" << endl;
    cout << "Estado:    " << p.estado << endl;
    cout << "======================" << endl;
}

int main() {
    Paquete paquete = leerPaquete();
    entregarPaquete(paquete);
    cout << "\nLa estructura Paquete ocupa " << sizeof(Paquete) << " bytes." << endl;
    return 0;
}
