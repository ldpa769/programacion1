// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyala Arteaga.
// Fecha creación: 16/11/2026
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

struct structEstudiante {
    char ci[10];
    char nombres[30];
    char apellidos[30];
};

struct structNotas {
    char ci[10];
    char materia[30];
    int nota;
};

const char* ARCH_EST = "Estudiantes.bin";
const char* ARCH_NOTAS = "Notas.bin";

// Copia un string a un arreglo de char sin desbordarlo.
template <size_t N>
void copiar(char (&destino)[N], const string& texto) {
    strncpy(destino, texto.c_str(), N - 1);
    destino[N - 1] = '\0';
}

string leerTexto(const string& mensaje) {
    string t;
    cout << mensaje;
    getline(cin, t);
    return t;
}

int leerEntero(const string& mensaje) {
    while (true) {
        string linea = leerTexto(mensaje);
        try {
            size_t pos;
            int v = stoi(linea, &pos);
            if (pos == linea.size()) return v;
        } catch (...) {}
        cout << "Valor inválido, intente de nuevo." << endl;
    }
}

// Verifica si ya existe un estudiante con ese ci.
bool existeEstudiante(const string& ci) {
    ifstream f(ARCH_EST, ios::binary);
    structEstudiante e;
    while (f.read(reinterpret_cast<char*>(&e), sizeof(e))) {
        if (ci == e.ci) return true;
    }
    return false;
}

// Verifica si ya existe una nota de esa materia para ese ci.
bool existeNota(const string& ci, const string& materia) {
    ifstream f(ARCH_NOTAS, ios::binary);
    structNotas n;
    while (f.read(reinterpret_cast<char*>(&n), sizeof(n))) {
        if (ci == n.ci && materia == n.materia) return true;
    }
    return false;
}

void ingresarEstudiante() {
    string ci = leerTexto("CI (máx. 9 caracteres): ");
    if (ci.empty() || ci.size() > 9) {
        cout << "CI inválido." << endl;
        return;
    }
    if (existeEstudiante(ci)) {
        cout << "Ya existe un estudiante con ese CI." << endl;
        return;
    }
    string nombres = leerTexto("Nombres: ");
    string apellidos = leerTexto("Apellidos: ");

    structEstudiante e{};
    copiar(e.ci, ci);
    copiar(e.nombres, nombres);
    copiar(e.apellidos, apellidos);

    ofstream f(ARCH_EST, ios::binary | ios::app);
    f.write(reinterpret_cast<char*>(&e), sizeof(e));
    cout << "Estudiante guardado." << endl;
}

void ingresarNota() {
    string ci = leerTexto("CI del estudiante: ");
    if (!existeEstudiante(ci)) {
        cout << "El estudiante no existe. Registrelo primero." << endl;
        return;
    }
    string materia = leerTexto("Materia: ");
    if (materia.empty()) {
        cout << "Materia inválida." << endl;
        return;
    }
    if (existeNota(ci, materia)) {
        cout << "Ya existe una nota de esa materia para este estudiante." << endl;
        return;
    }
    int nota = leerEntero("Nota (0-100): ");
    if (nota < 0 || nota > 100) {
        cout << "La nota debe estar entre 0 y 100." << endl;
        return;
    }

    structNotas n{};
    copiar(n.ci, ci);
    copiar(n.materia, materia);
    n.nota = nota;

    ofstream f(ARCH_NOTAS, ios::binary | ios::app);
    f.write(reinterpret_cast<char*>(&n), sizeof(n));
    cout << "Nota guardada." << endl;
}

void reporte() {
    ifstream fe(ARCH_EST, ios::binary);
    if (!fe) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }
    structEstudiante e;
    cout << "\n===== REPORTE DE ESTUDIANTES Y NOTAS =====" << endl;
    while (fe.read(reinterpret_cast<char*>(&e), sizeof(e))) {
        cout << "\nCI: " << e.ci << " | " << e.nombres << " " << e.apellidos << endl;
        ifstream fn(ARCH_NOTAS, ios::binary);
        structNotas n;
        bool tiene = false;
        while (fn.read(reinterpret_cast<char*>(&n), sizeof(n))) {
            if (strcmp(n.ci, e.ci) == 0) {
                cout << "   - " << n.materia << ": " << n.nota << endl;
                tiene = true;
            }
        }
        if (!tiene) cout << "   (sin notas registradas)" << endl;
    }
}

void mostrarMenu() {
    cout << "\n=== MENU ===" << endl;
    cout << "1. Ingreso de datos estudiantes" << endl;
    cout << "2. Ingreso de materias y notas" << endl;
    cout << "3. Reporte de estudiantes y notas ingresadas" << endl;
    cout << "4. Salir" << endl;
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        opcion = leerEntero("Opción: ");
        switch (opcion) {
            case 1: ingresarEstudiante(); break;
            case 2: ingresarNota(); break;
            case 3: reporte(); break;
            case 4: cout << "Hasta luego." << endl; break;
            default: cout << "Opción inválida." << endl;
        }
    } while (opcion != 4);
    return 0;
}
