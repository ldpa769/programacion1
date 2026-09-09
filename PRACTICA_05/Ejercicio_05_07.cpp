// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 09/09/2026
// Número de ejercicio: 7

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void lanzarMonedas(int n, int &caras, int &cruces){
    caras = 0;
    cruces = 0;
    for(int i = 0; i < n; i++){
        int resultado = rand() % 2; // 0 = cara, 1 = cruz
        if(resultado == 0)
            caras++;
        else
            cruces++;
    }
}

int main(){
    srand(time(0));

    int n, caras, cruces;

    cout << "Ingrese el numero de lanzamientos: ";
    cin >> n;

    lanzarMonedas(n, caras, cruces);

    double porcentajeCaras = (double)caras / n * 100;
    double porcentajeCruces = (double)cruces / n * 100;

    cout << "Caras: " << caras << " (" << porcentajeCaras << "%)" << endl;
    cout << "Cruces: " << cruces << " (" << porcentajeCruces << "%)" << endl;

    return 0;
}
