#include<iostream>
using namespace std;

int main(){
    int a, b;

    cout << "Ingrese el primer numero: ";
    cin >> a;
    cout << "Ingrese el segundo numero (distinto al primero): ";
    cin >> b;


    while (a == b)
    {
        cout << "Los numeros deben ser distintos. Ingrese el segundo numero: ";
        cin >> b;
    }

    if (a > b)
    {
        cout << "Serie descendente:" << endl;
        for (int i = a; i >= b; i--)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "Serie ascendente:" << endl;
        for (int i = a; i <= b; i++)
        {
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}