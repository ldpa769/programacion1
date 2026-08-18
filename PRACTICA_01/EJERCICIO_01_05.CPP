// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del Estudiante: ING. MECATRONICA
// Fecha creación: 12/08/2026
#include<iostream>
using namespace std;
int main(){
int opcion;
cout<<"ingrese la opcion que desea del numero 1 al 7: ";
cin>>opcion;
switch (opcion)
{
case 1:
    cout<<" el dia 1 es lunes. ";
    break;
case 2:
    cout<<" el dia 2 es martes. ";
    break;
case 3:
    cout<<" el dia 3 es miercoles. ";
    break;
case 4:
    cout<<" el dia 4 es jueves. ";
    break;
case 5:
    cout<<" el dia 5 es viernes. ";
    break;
case 6:
    cout<<" el dia 6 es sabado. ";
    break;
case 7:
    cout<<" el dia 7 es domingo. ";
    break;
default:
cout<<"opcion invalida";
    break;
}
return 0;
}