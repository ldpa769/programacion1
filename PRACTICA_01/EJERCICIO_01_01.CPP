// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del Estudiante: ING. MECATRONICA
// Fecha creación: 12/08/2026

#include<iostream>
#include <locale.h>
using namespace std;
int main(){
    setlocale(LC_CTYPE, "");
int año;
cout<<"ingrese el año que desea: ";
cin>>año;
if (año%4==0)
{
    cout<<"su año es biciesto";
}
else{
    cout<<"su año no es biciesto";
}
return 0;
}
