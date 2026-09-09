// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera: ING MECATRONICA
// Fecha de Creación: 8/9/2026


#include <iostream>
#include <conio.h>

using namespace std;

void tiempo(int, int&, int&, int&);

int main(){
    int totalSeg, horas, min, seg;

    cout<<"digite numero total de segundos:"<<endl;
    cin>>totalSeg;
tiempo(totalSeg, horas, min, seg);

cout<<"\ntiempo equivalente a la cantidad de segundos digitados: "<<endl;
cout<<"horas: "<<horas<<endl;
cout<<"minutos: "<<min<<endl;
cout<<"segundos: "<<seg<<endl;
    getch();
    return 0;
}

void tiempo(int totalSeg, int& horas, int& min, int& seg){
    horas = totalSeg/3600;
    totalSeg = totalSeg % 3600;
    min = totalSeg/60;
    seg= totalSeg%60;
}