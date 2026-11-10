// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del estudiante: ING MECATRONICA.
// Fecha creación: 04/11/2026

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Estudiante {
    string nombres;
    int notaFinal;
};

void generarEstudiantes(vector<Estudiante>& estudiantes, int n) {
    for (int i = 0; i < n; i++) {
        Estudiante e;
        e.nombres = "Estudiante " + to_string(i + 1);
        e.notaFinal = rand() % 101;  // 0 a 100
        estudiantes.push_back(e);
    }
}

void mostrarListas(const vector<Estudiante>& estudiantes) {
    vector<string> aprobados, reprobados;
    for (const Estudiante& e : estudiantes) {
        string linea = e.nombres + " (" + to_string(e.notaFinal) + ")";
        if (e.notaFinal >= 60) aprobados.push_back(linea);
        else reprobados.push_back(linea);
    }

    cout << "\n--- APROBADOS (" << aprobados.size() << ") ---" << endl;
    for (const string& s : aprobados) cout << s << endl;

    cout << "\n--- REPROBADOS (" << reprobados.size() << ") ---" << endl;
    for (const string& s : reprobados) cout << s << endl;
}

int main() {
    srand(time(nullptr));
    int n;
    cout << "¿Cuántos estudiantes desea generar? ";
    cin >> n;

    vector<Estudiante> estudiantes;
    generarEstudiantes(estudiantes, n);
    mostrarListas(estudiantes);
    return 0;
}
