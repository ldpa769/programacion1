// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Carrera del estudiante: Ing. mecatronica
// Fecha creación: 28/08/2026

#include <iostream>

using namespace std;

double calcularAreaTriangulo(double base, double altura) {
    return (base * altura) / 2.0;
}

int main() {
    double base, altura;

    cout << "=== CALCULO DE AREA DE UN TRIANGULO ===" << endl;
    cout << "Ingrese la base del triangulo: ";
    cin >> base;
    cout << "Ingrese la altura del triangulo: ";
    cin >> altura;

    double area = calcularAreaTriangulo(base, altura);

    cout << "El area del triangulo es: " << area << endl;

    return 0;
}
