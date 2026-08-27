#include<iostream>
using namespace std;

int main(){
    int numero;
    int sumaDivisores = 0;

    cout << "Ingrese un numero: ";
    cin >> numero;

    // Buscamos los divisores propios (de 1 a numero-1)
    for (int i = 1; i < numero; i++)
    {
        if (numero % i == 0)
        {
            sumaDivisores += i;
        }
    }

    cout << "La suma de los divisores es: " << sumaDivisores << endl;

    if (sumaDivisores == numero)
    {
        cout << numero << " es un numero perfecto." << endl;
    }
    else
    {
        cout << numero << " NO es un numero perfecto." << endl;
    }

    return 0;
}