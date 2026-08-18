// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Carrera: ING. mecatronica
// Fecha de Creación: 10/08/2026
#include <iostream>
using namespace std;
int main(){
    int x,y,aux;
    cout<<"digite x:";cin>>x;
    cout<<"digite y:";cin>>y;

    aux= x;
    x=y;
    y=aux;

    cout<<" el nuevo valor de x es:"<<x<<endl<<"el valor de y es: "<<y;
}