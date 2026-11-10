// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del estudiante: ING MECATRONICA.
// Fecha creación: 04/11/2026

#include <iostream>
using namespace std;

struct Tiempo {
    int horas;
    int minutos;
    int segundos;
};

Tiempo leerTiempo(const string& etiqueta) {
    Tiempo t;
    cout << "--- " << etiqueta << " ---" << endl;
    cout << "Horas: ";    cin >> t.horas;
    cout << "Minutos: ";  cin >> t.minutos;
    cout << "Segundos: "; cin >> t.segundos;
    return t;
}

Tiempo sumarTiempos(const Tiempo& a, const Tiempo& b) {
    Tiempo r;
    r.segundos = a.segundos + b.segundos;
    r.minutos  = a.minutos + b.minutos + r.segundos / 60;
    r.segundos %= 60;
    r.horas    = a.horas + b.horas + r.minutos / 60;
    r.minutos %= 60;
    return r;
}

void mostrarTiempo(const Tiempo& t) {
    cout << t.horas << "h " << t.minutos << "m " << t.segundos << "s" << endl;
}

int main() {
    Tiempo t1 = leerTiempo("Tiempo 1");
    Tiempo t2 = leerTiempo("Tiempo 2");
    Tiempo suma = sumarTiempos(t1, t2);
    cout << "Suma: ";
    mostrarTiempo(suma);
    return 0;
}
