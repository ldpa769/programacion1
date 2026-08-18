// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del Estudiante: ING. MECATRONICA
// Fecha creación: 12/08/2026
#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"\ningrese un numero del 1 al 100: ";
    cin>>num;
    while (num<0 || num>100)
    {
    
    cout<<"\ningrese un numero del 1 al 100: ";
    cin>>num;    
    }
    cout<<"nota registrada";
    return 0;
}