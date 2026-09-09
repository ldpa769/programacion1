// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera: ING MECATRONICA
// Fecha de Creación: 8/9/2026

#include <iostream>
#include <conio.h>

using namespace std;

void intercambiar(int&, int&);

int main(){
int num1=10, num2= 15;

cout<<"el valor de num 1 es: "<<num1<<endl;
cout<<"el valor de num 2 es: "<<num2<<endl;
intercambiar(num1, num2);


cout<<"el nuevo valor de num 1 es: "<<num1<<endl;
cout<<"el nuevo valor de num 1 es: "<<num1<<endl;
    getch();
    return 0;
}

void intercambiar(int& num1, int& num2){

    int aux;

    aux=num1;
    num1=num2;
    num2= aux;
}