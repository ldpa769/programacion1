// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del Estudiante: ING. MECATRONICA
// Fecha creación: 12/08/2026
#include<iostream>
using namespace std;
int main() {
    float precio, precioFinal;
    float iva = 0.13; 

    cout << "Digite el precio del producto: ";
    cin >> precio;

    precioFinal = precio + (precio * iva);

    cout << "El precio con IVA es: " << precioFinal << endl;

    return 0;
}