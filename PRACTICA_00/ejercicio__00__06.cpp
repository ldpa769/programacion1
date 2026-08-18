// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Carrera: ING. mecatronica
// Fecha de Creación: 10/08/2026
#include <iostream>
using namespace std;
int main(){
float practica, teorica, participacion, nota_final;
cout<<"digite nota de practica: ";cin>>practica;
cout<<"digite nota teotica: ";cin>>teorica;
cout<<"digite nota de participacion: ";cin>>participacion;

practica *= 0.30;
teorica *= 0.60;
participacion *=0.10;

nota_final= practica+teorica+participacion;
cout<<"\nla nota final es: "<<nota_final;
return 0;
}