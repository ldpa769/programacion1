// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyala Arteaga.
// Fecha creación: 16/11/2026
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Pide nombres al usuario y los guarda uno por línea en el archivo.
void guardarNombres(const string& archivo) {
    ofstream salida(archivo);
    if (!salida) {
        cout << "No se pudo crear el archivo " << archivo << endl;
        return;
    }
    cout << "Ingrese nombres (línea vacía para terminar):" << endl;
    string nombre;
    while (true) {
        cout << "Nombre: ";
        if (!getline(cin, nombre) || nombre.empty()) break;
        salida << nombre << '\n';
    }
}

// Lee el archivo y muestra todos los nombres en consola.
void mostrarNombres(const string& archivo) {
    ifstream entrada(archivo);
    if (!entrada) {
        cout << "No se pudo abrir el archivo " << archivo << endl;
        return;
    }
    cout << "\n--- Nombres guardados ---" << endl;
    string nombre;
    int i = 1;
    while (getline(entrada, nombre)) {
        cout << i++ << ". " << nombre << endl;
    }
}

int main() {
    const string archivo = "nombres.txt";
    guardarNombres(archivo);
    mostrarNombres(archivo);
    return 0;
}
