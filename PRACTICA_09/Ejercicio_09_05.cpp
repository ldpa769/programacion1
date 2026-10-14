// Materia: Programación I, Paralelo 4
// Autor: Luis Puyal
// Fecha creación: 07/10/2026
// Número de ejercicio: 5

#include <iostream>
#include <vector>
using namespace std;

const int FILAS = 5;
const int ASIENTOS = 5;

typedef vector<vector<int>> Matriz;

Matriz crearSala() {
    return Matriz(FILAS, vector<int>(ASIENTOS, 0));
}

void mostrarSala(const Matriz &sala) {
    cout << "\n      ";
    for (int j = 0; j < ASIENTOS; j++) {
        cout << j + 1 << " ";
    }
    cout << endl;
    for (int i = 0; i < FILAS; i++) {
        cout << "Fila " << i + 1 << " ";
        for (int j = 0; j < ASIENTOS; j++) {
            cout << (sala[i][j] == 0 ? 'L' : 'O') << " ";
        }
        cout << endl;
    }
    cout << "(L = Libre, O = Ocupado)" << endl;
}

void comprarEntrada(Matriz &sala) {
    int fila, asiento;
    cout << "Fila (1-" << FILAS << "): ";
    cin >> fila;
    cout << "Asiento (1-" << ASIENTOS << "): ";
    cin >> asiento;

    if (fila < 1 || fila > FILAS || asiento < 1 || asiento > ASIENTOS) {
        cout << "Fila o asiento fuera de rango." << endl;
        return;
    }

    if (sala[fila - 1][asiento - 1] == 0) {
        sala[fila - 1][asiento - 1] = 1;
        cout << "Reserva exitosa" << endl;
    } else {
        cout << "Asiento no disponible" << endl;
    }
}

void mostrarEstadisticas(const Matriz &sala) {
    int ocupados = 0;
    int total = FILAS * ASIENTOS;
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < ASIENTOS; j++) {
            if (sala[i][j] == 1) {
                ocupados++;
            }
        }
    }
    int libres = total - ocupados;
    cout << "Asientos libres: " << libres << " ("
         << (libres * 100.0 / total) << "%)" << endl;
    cout << "Asientos ocupados: " << ocupados << " ("
         << (ocupados * 100.0 / total) << "%)" << endl;
}

int mostrarMenu() {
    int opcion;
    cout << "\n=== SALA DE CINE VIP ===" << endl;
    cout << "1. Mostrar la sala" << endl;
    cout << "2. Comprar entrada" << endl;
    cout << "3. Estadisticas" << endl;
    cout << "4. Salir" << endl;
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

int main() {
    Matriz sala = crearSala();
    int opcion;

    do {
        opcion = mostrarMenu();
        switch (opcion) {
            case 1:
                mostrarSala(sala);
                break;
            case 2:
                comprarEntrada(sala);
                break;
            case 3:
                mostrarEstadisticas(sala);
                break;
            case 4:
                cout << "Hasta luego." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);

    return 0;
}
