// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 09/09/2026
// Número de ejercicio: 9

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool esPrimo(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    srand(time(0));

    int N;
    cout << "Ingrese la cantidad de numeros a generar: ";
    cin >> N;

    int contadorPrimos = 0;

    cout << "\nNumeros generados: " << endl;
    for(int i = 0; i < N; i++){
        int numero = rand() % 10000 + 1; // numero entre 1 y 10000
        cout << numero << " ";

        if(esPrimo(numero))
            contadorPrimos++;
    }

    cout << "\n\nCantidad de numeros primos: " << contadorPrimos << endl;

    return 0;
}
