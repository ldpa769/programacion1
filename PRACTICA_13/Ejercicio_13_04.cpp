// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyala Arteaga.
// Fecha creación: 16/11/2026
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

struct Estudiante {
    char ci[15];
    char nombres[30];
    char apellidos[30];
    char materia[30];
    int paralelo;
};

struct NotaHab {
    char ci[15];
    char materia[30];
    int paralelo;
    double nota;
    double porcentaje;   // peso de la nota (ej. 33.33)
};

const char* ARCH_EST = "ESTUDIANTES.BIN";
const char* ARCH_NOTAS = "NOTAS_HAB.BIN";

template <size_t N>
void copiar(char (&destino)[N], const string& texto) {
    strncpy(destino, texto.c_str(), N - 1);
    destino[N - 1] = '\0';
}

string mayusculas(string s) {
    for (char& c : s) c = toupper(static_cast<unsigned char>(c));
    return s;
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

double leerReal(const string& mensaje) {
    while (true) {
        string linea = leerTexto(mensaje);
        try {
            size_t pos;
            double v = stod(linea, &pos);
            if (pos == linea.size()) return v;
        } catch (...) {}
        cout << "Valor inválido, intente de nuevo." << endl;
    }
}

vector<Estudiante> cargarEstudiantes() {
    vector<Estudiante> lista;
    ifstream f(ARCH_EST, ios::binary);
    Estudiante e;
    while (f.read(reinterpret_cast<char*>(&e), sizeof(e))) lista.push_back(e);
    return lista;
}

void guardarEstudiantes(const vector<Estudiante>& lista) {
    ofstream f(ARCH_EST, ios::binary | ios::trunc);
    for (const Estudiante& e : lista) f.write(reinterpret_cast<const char*>(&e), sizeof(e));
}

vector<NotaHab> cargarNotas() {
    vector<NotaHab> lista;
    ifstream f(ARCH_NOTAS, ios::binary);
    NotaHab n;
    while (f.read(reinterpret_cast<char*>(&n), sizeof(n))) lista.push_back(n);
    return lista;
}

void guardarNotas(const vector<NotaHab>& lista) {
    ofstream f(ARCH_NOTAS, ios::binary | ios::trunc);
    for (const NotaHab& n : lista) f.write(reinterpret_cast<const char*>(&n), sizeof(n));
}

// Un estudiante se identifica por CI + materia + paralelo.
bool mismoEstudiante(const Estudiante& e, const string& ci, const string& materia, int paralelo) {
    return ci == e.ci && materia == e.materia && paralelo == e.paralelo;
}

int buscarEstudiante(const vector<Estudiante>& lista, const string& ci,
                     const string& materia, int paralelo) {
    for (size_t i = 0; i < lista.size(); i++) {
        if (mismoEstudiante(lista[i], ci, materia, paralelo)) return static_cast<int>(i);
    }
    return -1;
}

void adicionarEstudiante() {
    vector<Estudiante> lista = cargarEstudiantes();
    Estudiante e{};
    string ci = leerTexto("Carnet de identidad: ");
    string nombres = mayusculas(leerTexto("Nombres: "));
    string apellidos = mayusculas(leerTexto("Apellidos: "));
    string materia = mayusculas(leerTexto("Materia: "));
    int paralelo = leerEntero("Paralelo: ");
    if (ci.empty() || materia.empty()) {
        cout << "Datos inválidos." << endl;
        return;
    }
    if (buscarEstudiante(lista, ci, materia, paralelo) >= 0) {
        cout << "Ese estudiante ya está registrado en esa materia y paralelo." << endl;
        return;
    }
    copiar(e.ci, ci);
    copiar(e.nombres, nombres);
    copiar(e.apellidos, apellidos);
    copiar(e.materia, materia);
    e.paralelo = paralelo;
    lista.push_back(e);
    guardarEstudiantes(lista);
    cout << "Estudiante agregado." << endl;
}

// Calcula la nota final ponderada, el porcentaje acumulado y si hay alguna nota < 60.
void resumenNotas(const vector<NotaHab>& notas, const Estudiante& e,
                  double& notaFinal, double& porcentaje, bool& hayMenor, int& cantidad) {
    notaFinal = 0;
    porcentaje = 0;
    hayMenor = false;
    cantidad = 0;
    for (const NotaHab& n : notas) {
        if (strcmp(n.ci, e.ci) == 0 && strcmp(n.materia, e.materia) == 0 && n.paralelo == e.paralelo) {
            notaFinal += n.nota * n.porcentaje / 100.0;
            porcentaje += n.porcentaje;
            if (n.nota < 60) hayMenor = true;
            cantidad++;
        }
    }
}

void listarHabilitados() {
    vector<Estudiante> estudiantes = cargarEstudiantes();
    if (estudiantes.empty()) {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }
    vector<NotaHab> notas = cargarNotas();

    cout << "\n" << left << setw(10) << "CARNET" << setw(14) << "NOMBRES" << setw(14) << "APELLIDOS"
         << setw(18) << "MATERIA" << setw(10) << "PARALELO" << setw(18) << "NOTA HABILITACION"
         << "ESTADO" << endl;

    double suma = 0;
    for (const Estudiante& e : estudiantes) {
        double notaFinal, porcentaje;
        bool hayMenor;
        int cantidad;
        resumenNotas(notas, e, notaFinal, porcentaje, hayMenor, cantidad);

        string estado;
        if (cantidad == 0) estado = "SIN NOTAS";
        else if (hayMenor) estado = "NO HABILITADO, TIENE UNA NOTA MENOR A 60";
        else if (porcentaje < 99.9) estado = "NOTAS INCOMPLETAS";
        else estado = "HABILITADO";

        cout << left << setw(10) << e.ci << setw(14) << e.nombres << setw(14) << e.apellidos
             << setw(18) << e.materia << setw(10) << e.paralelo
             << setw(18) << fixed << setprecision(1) << notaFinal << estado << endl;
        suma += notaFinal;
    }
    cout << "\nPromedio de notas de habilitación: " << fixed << setprecision(2)
         << suma / estudiantes.size() << endl;
}

void eliminarEstudiante() {
    vector<Estudiante> lista = cargarEstudiantes();
    string ci = leerTexto("Carnet del estudiante: ");
    string materia = mayusculas(leerTexto("Materia: "));
    int paralelo = leerEntero("Paralelo: ");
    int pos = buscarEstudiante(lista, ci, materia, paralelo);
    if (pos < 0) {
        cout << "Estudiante no encontrado." << endl;
        return;
    }
    lista.erase(lista.begin() + pos);
    guardarEstudiantes(lista);

    // También se eliminan sus notas de habilitación.
    vector<NotaHab> notas = cargarNotas(), restantes;
    for (const NotaHab& n : notas) {
        if (!(ci == n.ci && materia == n.materia && paralelo == n.paralelo)) restantes.push_back(n);
    }
    guardarNotas(restantes);
    cout << "Estudiante eliminado." << endl;
}

void adicionarNota() {
    vector<Estudiante> estudiantes = cargarEstudiantes();
    string ci = leerTexto("Carnet del estudiante: ");
    string materia = mayusculas(leerTexto("Materia: "));
    int paralelo = leerEntero("Paralelo: ");
    if (buscarEstudiante(estudiantes, ci, materia, paralelo) < 0) {
        cout << "El estudiante no existe en esa materia y paralelo." << endl;
        return;
    }
    double nota = leerReal("Nota (0-100): ");
    double pct = leerReal("Porcentaje de la nota (ej. 33.33): ");
    if (nota < 0 || nota > 100 || pct <= 0 || pct > 100) {
        cout << "Nota o porcentaje inválido." << endl;
        return;
    }
    // Verifica que los porcentajes acumulados no pasen de 100.
    vector<NotaHab> notas = cargarNotas();
    double acumulado = 0;
    for (const NotaHab& n : notas) {
        if (ci == n.ci && materia == n.materia && paralelo == n.paralelo) acumulado += n.porcentaje;
    }
    if (acumulado + pct > 100.01) {
        cout << "Los porcentajes superan el 100% (acumulado actual: " << acumulado << "%)." << endl;
        return;
    }
    NotaHab n{};
    copiar(n.ci, ci);
    copiar(n.materia, materia);
    n.paralelo = paralelo;
    n.nota = nota;
    n.porcentaje = pct;
    notas.push_back(n);
    guardarNotas(notas);
    cout << "Nota registrada." << endl;
}

void mostrarMenu() {
    cout << "\n=== MENU NOTAS UCB ===" << endl;
    cout << "1. Adicionar Estudiante" << endl;
    cout << "2. Listado de Estudiantes Habilitados" << endl;
    cout << "3. Eliminar un Estudiante" << endl;
    cout << "4. Adicionar notas habilitación" << endl;
    cout << "5. Salir" << endl;
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        opcion = leerEntero("Opción: ");
        switch (opcion) {
            case 1: adicionarEstudiante(); break;
            case 2: listarHabilitados(); break;
            case 3: eliminarEstudiante(); break;
            case 4: adicionarNota(); break;
            case 5: cout << "Hasta luego." << endl; break;
            default: cout << "Opción inválida." << endl;
        }
    } while (opcion != 5);
    return 0;
}
