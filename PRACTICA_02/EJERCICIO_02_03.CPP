// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera: ING. MECATRONICA
// Fecha de Creación: 17/08/2026

#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
int numero, suma=0;

do{
    cout<<"digite un numero: ";
    cin>>numero;

    if (numero>0)
    {
        suma+=numero; 
    }
    
}while (numero<20 || numero>30 && numero !=0);

cout<<"\nel resultado es: "<<suma<<endl;

system("pause");
return 0;
}