// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Carrera: ING. mecatronica
// Fecha de Creación: 10/08/2026
#include <iostream>
using namespace std;
int main(){
    float a,b,c, d, e, f,  resultado;
    cout<<"digite valor de a: ";cin>>a;
    cout<<"digite valor de b: ";cin>>b;
    cout<<"digite valor de c: ";cin>>c;
    cout<<"digite valor de d: ";cin>>d;
    cout<<"digite valor de e: ";cin>>e;
    cout<<"digite valor de f: ";cin>>f;
    resultado= (a+(b/c))/(d+(e/f));

    cout<<"\nel resultado es: "<<resultado;
    return 0;

}