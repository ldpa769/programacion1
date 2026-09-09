// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 09/09/2026
// Número de ejercicio: 2

#include <iostream>
using namespace std;

void ModificarValores(int valor, int &referencia){
    valor = valor * 2;
    referencia = referencia + 10;

    cout << "Dentro de la funcion -> valor (local): " << valor
         << ", referencia: " << referencia << endl;
}

int main(){
    int a, b;

    cout << "Ingrese dos numeros enteros: ";
    cin >> a >> b;

    cout << "Antes de la llamada: a = " << a << ", b = " << b << endl;

    ModificarValores(a, b);

    cout << "Despues de la llamada: a = " << a << ", b = " << b << endl;

    return 0;
}
