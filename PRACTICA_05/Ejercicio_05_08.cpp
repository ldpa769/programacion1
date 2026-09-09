// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 09/09/2026
// Número de ejercicio: 8

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

long long factorial(int n){
    long long resultado = 1;
    for(int i = 1; i <= n; i++){
        resultado *= i;
    }
    return resultado;
}

int main(){
    srand(time(0));

    int numero = rand() % 10 + 1; // numero entre 1 y 10

    cout << "Numero aleatorio generado: " << numero << endl;
    cout << "Factorial de " << numero << " = " << factorial(numero) << endl;

    return 0;
}
