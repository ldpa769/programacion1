// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera: ING. MECATRONICA
// Fecha de Creación: 17/08/2026
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){

    int numero, factorial=1;
    cout<<"digite un numero: ";
    cin>>numero;

    for (int i = 1; i <= numero; i++)
    {
        factorial*=i;
    }
    cout<<"\nfactorial el numero es: "<<factorial<<endl;
system("pause");
return 0;
}