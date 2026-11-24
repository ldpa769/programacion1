// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyala Arteaga.
// Fecha creación: 16/11/2026
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const string ARCHIVO = "estudiantes.txt";

// Lee un entero válido desde la consola.
int leerEntero(const string& mensaje) {
    while (true) {
        cout << mensaje;
        string linea;
        getline(cin, linea);
        try {
            size_t pos;
            int valor = stoi(linea, &pos);
            if (pos == linea.size()) return valor;
        } catch (...) {}
        cout << "Valor inválido, intente de nuevo." << endl;
    }
}

// Lee un número real válido desde la consola.
double leerReal(const string& mensaje) {
    while (true) {
        cout << mensaje;
        string linea;
        getline(cin, linea);
        try {
            size_t pos;
            double valor = stod(linea, &pos);
            if (pos == linea.size()) return valor;
        } catch (...) {}
        cout << "Valor inválido, intente de nuevo." << endl;
    }
}

// Agrega un estudiante al final del archivo con el formato pedido.
void registrarEstudiante() {
    ofstream salida(ARCHIVO, ios::app);
    if (!salida) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }
    string nombre;
    cout << "Nombre: ";
    getline(cin, nombre);
    int edad = leerEntero("Edad: ");
    double promedio = leerReal("Promedio: ");

    salida << "Nombre: " << nombre << '\n'
           << "Edad: " << edad << '\n'
           << "Promedio: " << promedio << "\n\n";
    cout << "Estudiante registrado." << endl;
}

// Lee el archivo y muestra los estudiantes en una tabla.
void mostrarEstudiantes() {
    ifstream entrada(ARCHIVO);
    if (!entrada) {
        cout << "Aún no hay estudiantes registrados." << endl;
        return;
    }
    cout << "\n" << left << setw(20) << "NOMBRE" << setw(8) << "EDAD" << "PROMEDIO" << endl;
    cout << string(36, '-') << endl;

    string linea, nombre, edad, promedio;
    int total = 0;
    while (getline(entrada, linea)) {
        if (linea.rfind("Nombre: ", 0) == 0) {
            nombre = linea.substr(8);
        } else if (linea.rfind("Edad: ", 0) == 0) {
            edad = linea.substr(6);
        } else if (linea.rfind("Promedio: ", 0) == 0) {
            promedio = linea.substr(10);
            cout << left << setw(20) << nombre << setw(8) << edad << promedio << endl;
            total++;
        }
    }
    cout << string(36, '-') << endl;
    cout << "Total de estudiantes: " << total << endl;
}

void mostrarMenu() {
    cout << "\n=== REGISTRO DE ESTUDIANTES ===" << endl;
    cout << "1. Registrar estudiante" << endl;
    cout << "2. Mostrar estudiantes" << endl;
    cout << "3. Salir" << endl;
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        opcion = leerEntero("Opción: ");
        switch (opcion) {
            case 1: registrarEstudiante(); break;
            case 2: mostrarEstudiantes(); break;
            case 3: cout << "Hasta luego." << endl; break;
            default: cout << "Opción inválida." << endl;
        }
    } while (opcion != 3);
    return 0;
}
