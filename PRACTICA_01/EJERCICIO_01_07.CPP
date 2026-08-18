// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del Estudiante: ING. MECATRONICA
// Fecha creación: 12/08/2026
#include <iostream>

using namespace std;

int main() {
    int num, auxiliar;
    int cantidad_digitos = 0;
    int suma_digitos = 0;

    cout << "Ingresa un numero entero positivo N: ";
    cin >> num;

    if (num <= 0) {
        cout << "El numero debe ser entero y positivo." ;
        return 0;
    }

    auxiliar = num;

    while (auxiliar > 0) {
        suma_digitos += auxiliar % 10;   // Suma el último dígito
        cantidad_digitos++;             // Cuenta el dígito
        auxiliar /= 10;                 // Elimina el último dígito
    }

    // Mostrar los resultados
    cout << "El numero " << num << " tiene " << cantidad_digitos << " digitos." << endl;
    cout << "La suma de sus digitos es: " << suma_digitos << endl;

    return 0;
}