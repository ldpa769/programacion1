// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del estudiante: ING MECATRONICA.
// Fecha creación: 04/11/2026

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Tarea {
    string descripcion;
    bool completada;
};

void registrarTareas(vector<Tarea>& tareas, int n) {
    for (int i = 0; i < n; i++) {
        Tarea t;
        cout << "Descripción de la tarea " << i + 1 << ": ";
        getline(cin, t.descripcion);
        t.completada = false;
        tareas.push_back(t);
    }
}

void mostrarPendientes(const vector<Tarea>& tareas) {
    bool hay = false;
    cout << "\n--- Tareas pendientes ---" << endl;
    for (size_t i = 0; i < tareas.size(); i++) {
        if (!tareas[i].completada) {
            cout << i << ". " << tareas[i].descripcion << endl;
            hay = true;
        }
    }
    if (!hay) cout << "No hay tareas pendientes." << endl;
}

void completarTarea(vector<Tarea>& tareas, int indice) {
    if (indice < 0 || indice >= (int)tareas.size()) {
        cout << "Índice inválido." << endl;
        return;
    }
    tareas[indice].completada = true;
    cout << "Tarea \"" << tareas[indice].descripcion << "\" completada." << endl;
}

int mostrarMenu() {
    int opcion;
    cout << "\n===== MENÚ =====" << endl;
    cout << "1. Mostrar tareas pendientes" << endl;
    cout << "2. Marcar tarea como completada" << endl;
    cout << "3. Salir" << endl;
    cout << "Opción: ";
    cin >> opcion;
    return opcion;
}

int main() {
    int n;
    cout << "¿Cuántas tareas desea ingresar? ";
    cin >> n;
    cin.ignore();

    vector<Tarea> tareas;
    registrarTareas(tareas, n);

    int opcion;
    do {
        opcion = mostrarMenu();
        if (opcion == 1) {
            mostrarPendientes(tareas);
        } else if (opcion == 2) {
            int indice;
            cout << "Índice de la tarea: ";
            cin >> indice;
            completarTarea(tareas, indice);
        } else if (opcion != 3) {
            cout << "Opción no válida." << endl;
        }
    } while (opcion != 3);
    return 0;
}
