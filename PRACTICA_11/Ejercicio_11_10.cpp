// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del estudiante: ING MECATRONICA.
// Fecha creación: 04/11/2026


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

struct Equipo {
    string nombre;
    int partidosJugados;
    int victorias;
    int puntosTotales;
};

void registrarEquipos(vector<Equipo>& equipos, int n) {
    for (int i = 0; i < n; i++) {
        Equipo e;
        cout << "Nombre del equipo " << i + 1 << ": ";
        getline(cin, e.nombre);
        e.partidosJugados = 0;
        e.victorias = 0;
        e.puntosTotales = 0;
        equipos.push_back(e);
    }
}

int buscarEquipo(const vector<Equipo>& equipos, const string& nombre) {
    for (size_t i = 0; i < equipos.size(); i++)
        if (equipos[i].nombre == nombre) return (int)i;
    return -1;
}

void simularPartido(vector<Equipo>& equipos) {
    if (equipos.size() < 2) {
        cout << "Se necesitan al menos 2 equipos." << endl;
        return;
    }
    // Escoger dos equipos distintos al azar
    int a = rand() % equipos.size();
    int b;
    do {
        b = rand() % equipos.size();
    } while (b == a);

    string nombreA = equipos[a].nombre;
    string nombreB = equipos[b].nombre;
    cout << "\nPartido: " << nombreA << " vs " << nombreB << endl;

    // Resultado aleatorio
    string ganador = (rand() % 2 == 0) ? nombreA : nombreB;
    string perdedor = (ganador == nombreA) ? nombreB : nombreA;

    // Buscar ambos equipos en el vector y actualizar
    int iG = buscarEquipo(equipos, ganador);
    int iP = buscarEquipo(equipos, perdedor);
    equipos[iG].victorias++;
    equipos[iG].partidosJugados++;
    equipos[iG].puntosTotales += 3;
    equipos[iP].partidosJugados++;

    cout << "Ganador: " << ganador << endl;
}

void ordenarClasificacion(vector<Equipo>& equipos) {
    sort(equipos.begin(), equipos.end(), [](const Equipo& x, const Equipo& y) {
        return x.puntosTotales > y.puntosTotales;
    });
}

void imprimirTabla(const vector<Equipo>& equipos) {
    cout << "\n" << left << setw(9) << "Posición" << "| " << setw(15) << "Equipo"
         << "| " << setw(8) << "Jugados" << "| " << setw(10) << "Victorias"
         << "| " << "Puntos" << endl;
    cout << string(55, '-') << endl;
    for (size_t i = 0; i < equipos.size(); i++) {
        cout << left << setw(9) << i + 1 << "| " << setw(15) << equipos[i].nombre
             << "| " << setw(8) << equipos[i].partidosJugados
             << "| " << setw(10) << equipos[i].victorias
             << "| " << equipos[i].puntosTotales << endl;
    }
}

int main() {
    srand(time(nullptr));
    int n;
    cout << "¿Cuántos equipos participan? ";
    cin >> n;
    cin.ignore();

    vector<Equipo> equipos;
    registrarEquipos(equipos, n);

    int partidos;
    cout << "¿Cuántos partidos desea simular? ";
    cin >> partidos;
    for (int i = 0; i < partidos; i++) simularPartido(equipos);

    ordenarClasificacion(equipos);
    imprimirTabla(equipos);
    return 0;
}
