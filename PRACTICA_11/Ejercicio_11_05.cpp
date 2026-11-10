// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del estudiante: ING MECATRONICA.
// Fecha creación: 04/11/2026


#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Cancion {
    string titulo;
    string artista;
    int duracionSegundos;
};

void registrarCanciones(vector<Cancion>& canciones, int n) {
    for (int i = 0; i < n; i++) {
        Cancion c;
        cout << "\nCanción " << i + 1 << endl;
        cout << "Título: ";
        getline(cin, c.titulo);
        cout << "Artista: ";
        getline(cin, c.artista);
        cout << "Duración (segundos): ";
        cin >> c.duracionSegundos;
        cin.ignore();
        canciones.push_back(c);
    }
}

void duracionTotal(const vector<Cancion>& canciones) {
    int total = 0;
    for (const Cancion& c : canciones) total += c.duracionSegundos;
    cout << "\nDuración total: " << total / 60 << " minutos y "
         << total % 60 << " segundos" << endl;
}

int main() {
    int n;
    cout << "¿Cuántas canciones desea registrar? ";
    cin >> n;
    cin.ignore();

    vector<Cancion> canciones;
    registrarCanciones(canciones, n);
    duracionTotal(canciones);
    return 0;
}
