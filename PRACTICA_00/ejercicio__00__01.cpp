// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Carrera: ING. mecatronica
// Fecha de Creación: 10/08/2026

#include <iostream>
using namespace std;

int main(){
int n1, n2, suma, resta , multiplicacion, division;

cout<<" digite un numero: ";
cin>> n1;

cout<<" digite otro numero: ";
cin>> n2;

suma = n1+n2;
resta = n1-n2;
division = n1/n2;
multiplicacion = n1*n2;

cout<<"\nLa suma es: "<<suma<<endl;

cout<<"\nLa resta es: "<<resta<<endl;
cout<<"\nLa division es: "<<division<<endl;
cout<<"\nLa multiplicacion es: "<<multiplicacion<<endl;

return 0;

}
