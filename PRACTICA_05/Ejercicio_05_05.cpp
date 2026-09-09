// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 09/09/2026
// Número de ejercicio: 5

#include <iostream>
using namespace std;

void calcularTiempo(int totalSegundos, int &horas, int &minutos, int &segundos){
    horas = totalSegundos / 3600;
    minutos = (totalSegundos % 3600) / 60;
    segundos = totalSegundos % 60;
}

int main(){
    int totalSegundos, h, m, s;

    cout << "Ingrese el total de segundos: ";
    cin >> totalSegundos;

    calcularTiempo(totalSegundos, h, m, s);

    cout << totalSegundos << " segundos equivalen a: "
         << h << " horas, " << m << " minutos, " << s << " segundos" << endl;

    return 0;
}
