// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera: ING. MECATRONICA
// Fecha de Creación: 17/08/2026

#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int NumAleatorio(int min, int max);
bool esPrimo(int numero);

int main(){
    int n;
    int numero = 0;
    int sum_total = 0;
    int sum_pares = 0;
    int sum_impares = 0;
    int suma_primos = 0;

    srand(time(0)); // Se llama UNA sola vez, al inicio

    cout << "Ingrese la cantidad de numeros a generar: " << endl;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        numero = NumAleatorio(1, 100);
        cout << "Numero " << i << ": " << numero << endl;

        sum_total += numero;

        if (numero % 2 == 0)
        {
            sum_pares += numero;
        }
        else
        {
            sum_impares += numero;
        }

        // Chequeo de primo INDEPENDIENTE del par/impar
        if (esPrimo(numero))
        {
            suma_primos += numero;
        }
    }

    cout << "\n--- Resultados ---" << endl;
    cout << "Suma total: " << sum_total << endl;
    cout << "Suma de pares: " << sum_pares << endl;
    cout << "Suma de impares: " << sum_impares << endl;
    cout << "Suma de primos: " << suma_primos << endl;

    return 0;
}

int NumAleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

bool esPrimo(int numero)
{
    if (numero < 2) return false;
    for (int i = 2; i * i <= numero; i++)
    {
        if (numero % i == 0)
        {
            return false;
        }
    }
    return true;
}