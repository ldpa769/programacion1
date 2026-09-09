// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 09/09/2026
// Número de ejercicio: 1

#include <iostream>
using namespace std;

void IntercambiarValores(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(){
    int x, y;

    cout << "Ingrese dos numeros enteros: ";
    cin >> x >> y;

    cout << "Antes del intercambio: x = " << x << ", y = " << y << endl;

    IntercambiarValores(x, y);

    cout << "Despues del intercambio: x = " << x << ", y = " << y << endl;

    return 0;
}
