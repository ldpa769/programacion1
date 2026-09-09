// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 09/09/2026
// Número de ejercicio: 12

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Genera aleatoriamente la cantidad de ninos de 1, 2 y 3 anios
// de forma que la suma no sobrepase N
void generarNinos(int N, int &ninos1, int &ninos2, int &ninos3){
    ninos1 = rand() % (N + 1);
    ninos2 = rand() % (N - ninos1 + 1);
    ninos3 = N - ninos1 - ninos2;
}

int main(){
    srand(time(0));

    int N;
    cout << "Ingrese el numero total de ninos (N): ";
    cin >> N;

    int ninos1, ninos2, ninos3;
    generarNinos(N, ninos1, ninos2, ninos3);

    int panales1 = ninos1 * 6;
    int panales2 = ninos2 * 3;
    int panales3 = ninos3 * 2;
    int totalPanales = panales1 + panales2 + panales3;

    cout << "\nNinos de 1 anio: " << ninos1 << " -> " << panales1 << " panales" << endl;
    cout << "Ninos de 2 anios: " << ninos2 << " -> " << panales2 << " panales" << endl;
    cout << "Ninos de 3 anios: " << ninos3 << " -> " << panales3 << " panales" << endl;

    cout << "\nConsumo total de panales por dia: " << totalPanales << endl;

    return 0;
}
