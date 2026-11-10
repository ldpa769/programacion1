// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del estudiante: ING MECATRONICA.
// Fecha creación: 04/11/2026

#include <iostream>
#include <string>
using namespace std;

struct Jugador {
    string nickname;
    int nivel;
    int experiencia;
};

Jugador leerJugador() {
    Jugador j;
    cout << "Nickname: ";
    getline(cin, j.nickname);
    cout << "Nivel: ";
    cin >> j.nivel;
    cout << "Experiencia: ";
    cin >> j.experiencia;
    return j;
}

void mostrarJugador(const Jugador& j) {
    cout << "Nickname: " << j.nickname << " | Nivel: " << j.nivel
         << " | Experiencia: " << j.experiencia << endl;
}

void sumarExperiencia(Jugador& j, int puntos) {
    j.experiencia += puntos;
    if (j.experiencia > 100) {
        j.nivel++;
        j.experiencia = 0;
    }
}

int main() {
    Jugador jugador = leerJugador();

    int puntos;
    cout << "Puntos de experiencia a sumar: ";
    cin >> puntos;

    cout << "\n--- Antes ---" << endl;
    mostrarJugador(jugador);

    sumarExperiencia(jugador, puntos);

    cout << "--- Después ---" << endl;
    mostrarJugador(jugador);
    return 0;
}
