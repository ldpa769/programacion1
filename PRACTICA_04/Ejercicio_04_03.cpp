// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Carrera del estudiante: Ing. mecatronica
// Fecha creación: 28/08/2026

#include <iostream>

using namespace std;

const double PI = 3.14159265358979;

double calcularVolumenCilindro(double radio, double altura) {
    return PI * radio * radio * altura;
}

int main() {
    double radio, altura;

    cout << "=== CALCULO DE VOLUMEN DE UN CILINDRO ===" << endl;
    cout << "Ingrese el radio del cilindro: ";
    cin >> radio;
    cout << "Ingrese la altura del cilindro: ";
    cin >> altura;

    double volumen = calcularVolumenCilindro(radio, altura);

    cout << "El volumen del cilindro es: " << volumen << endl;

    return 0;
}
