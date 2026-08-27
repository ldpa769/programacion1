// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera: ING. MECATRONICA
// Fecha de Creación: 17/08/2026
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
int n ,suma=0;

cout<<"digite el numero de elementos: ";
cin>>n;
for (int i = 1; i <=n; i++)
{
    suma+=i;
}

cout<<"la suma es: "<<suma;
return 0;

}