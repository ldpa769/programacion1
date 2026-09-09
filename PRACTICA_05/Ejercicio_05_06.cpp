// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 09/09/2026
// Número de ejercicio: 6

#include <iostream>
using namespace std;

void agregarNota(double &sumaTotal, int &cantidadNotas, double nuevaNota){
    sumaTotal += nuevaNota;
    cantidadNotas++;
}

int main(){
    int N;
    double sumaTotal = 0;
    int cantidadNotas = 0;
    double nota;

    cout << "Ingrese la cantidad de notas a registrar: ";
    cin >> N;

    for(int i = 0; i < N; i++){
        cout << "Ingrese la nota #" << (i + 1) << ": ";
        cin >> nota;
        agregarNota(sumaTotal, cantidadNotas, nota);
    }

    cout << "\nCantidad de notas registradas: " << cantidadNotas << endl;
    cout << "Suma total: " << sumaTotal << endl;
    if(cantidadNotas > 0)
        cout << "Promedio: " << sumaTotal / cantidadNotas << endl;

    return 0;
}
