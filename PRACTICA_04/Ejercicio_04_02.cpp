// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Carrera del estudiante: Ing. mecatronica
// Fecha creación: 28/08/2026


#include <iostream>

using namespace std;

int obtenerMayor(int a, int b, int c) {
    int mayor = a;

    if (b > mayor) {
        mayor = b;
    }
    if (c > mayor) {
        mayor = c;
    }

    return mayor;
}

int main() {
    int num1, num2, num3;

    cout << "=== DETERMINACION DE MAYORIA ===" << endl;
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    cout << "Ingrese el tercer numero: ";
    cin >> num3;

    int mayor = obtenerMayor(num1, num2, num3);

    cout << "El numero mayor es: " << mayor << endl;

    return 0;
}
