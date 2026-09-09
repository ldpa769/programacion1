// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 09/09/2026
// Número de ejercicio: 10
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

    int sumaPares = 0;
    double sumaImpares = 0;
    int cantidadImpares = 0;
    int mayorPrimo = -1;

    cout << "\nNumeros generados: " << endl;
    for(int i = 0; i < N; i++){
        int numero = rand() % 1000 + 1; // numero entre 1 y 1000
        cout << numero << " ";

        if(numero % 2 == 0){
            sumaPares += numero;
        } else {
            sumaImpares += numero;
            cantidadImpares++;
        }

        if(esPrimo(numero) && numero > mayorPrimo){
            mayorPrimo = numero;
        }
    }

    cout << "\n\na. Sumatoria de numeros pares: " << sumaPares << endl;

    if(cantidadImpares > 0)
        cout << "b. Promedio de numeros impares: " << sumaImpares / cantidadImpares << endl;
    else
        cout << "b. No se generaron numeros impares." << endl;

    if(mayorPrimo != -1)
        cout << "c. Mayor numero primo generado: " << mayorPrimo << endl;
    else
        cout << "c. No se genero ningun numero primo." << endl;

    return 0;
}
