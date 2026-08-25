// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera: ING. MECATRONICA
// Fecha de Creación: 17/08/2026
#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main(){
    int numero, dato, contador = 0;

    srand(time(NULL));
    dato=1 + rand() % (100);

    do
    {
        cout<<"digite un numero: ";
        cin>>numero;
        if (numero>dato)
        {
            cout<<"\nDigite un numero menor\n";
        }
        if (numero<dato)
        {
            cout<<"\nDigite un numero mayor\n";
        }
        contador++;
    } while (numero != dato);
    
cout<<"\nFELICIDADES ADIVINASTE EL NUMERO\n";
cout<<"numero de intentos: "<<contador<<endl;

    system("pause");
    return 0;
}