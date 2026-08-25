// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera: ING. MECATRONICA
// Fecha de Creación: 17/08/2026

#include <iostream>
using namespace std;

int main(){
    int numero;

    do
    {
        cout<<"digite un numero del 1 al 10: ";
        cin>>numero;
    } while ((numero<1) || (numero>10));
    
    for (int i = 1; i <= 20; i++)
    {
        cout<<numero<<" * "<< i <<" = "<<numero*i<<endl;
    }
    return 0;
}