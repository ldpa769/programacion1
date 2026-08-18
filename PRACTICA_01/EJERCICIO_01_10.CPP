// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del Estudiante: ING. MECATRONICA
// Fecha creación: 12/08/2026
#include<iostream>
using namespace std;
int main(){
int opcion;
cout<<"ingrese la opcion que desea del numero 1 al 12: ";
cin>>opcion;
switch (opcion)
{
case 1:
    cout<<" el mes 1 es enero. ";
    break;
case 2:
    cout<<" el mes 2 es febrero. ";
    break;
case 3:
    cout<<" el mes 3 es marzo. ";
    break;
case 4:
    cout<<" el mes 4 es abril. ";
    break;
case 5:
    cout<<" el mes 5 es mayo. ";
    break;
case 6:
    cout<<" el mes 6 es junio. ";
    break;
case 7:
    cout<<" el mes 7 es julio. ";
    break;
case 8:
    cout<<" el mes 8 es agosto. ";
    break;
case 9:
    cout<<" el mes 9 es septiempre. ";
    break;
case 10:
    cout<<" el mes 10 es octubre. ";
    break;
case 11:
    cout<<" el mes 11 es noviembre. ";
    break;
case 12:
    cout<<"  mes 12 es diciembre. ";
    break;
default:
cout<<"opcion invalida";
    break;
}
return 0;
}

