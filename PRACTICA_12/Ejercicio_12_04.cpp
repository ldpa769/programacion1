// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyala Arteaga.
// Fecha creación: 16/11/2026
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Cuenta cuántas veces aparece 'buscado' en una línea (sin solaparse).
int contarEnLinea(const string& linea, const string& buscado) {
    int cuenta = 0;
    size_t pos = linea.find(buscado);
    while (pos != string::npos) {
        cuenta++;
        pos = linea.find(buscado, pos + buscado.size());
    }
    return cuenta;
}

// Cuenta las apariciones en todo el archivo. Devuelve -1 si no se pudo abrir.
int contarEnArchivo(const string& archivo, const string& buscado) {
    ifstream entrada(archivo);
    if (!entrada) return -1;
    int total = 0;
    string linea;
    while (getline(entrada, linea)) {
        total += contarEnLinea(linea, buscado);
    }
    return total;
}

int main() {
    const string archivo = "datos.txt";
    string buscado;
    cout << "Ingrese la palabra o frase a buscar: ";
    getline(cin, buscado);
    if (buscado.empty()) {
        cout << "Debe ingresar un texto." << endl;
        return 1;
    }

    int veces = contarEnArchivo(archivo, buscado);
    if (veces < 0) {
        cout << "No se pudo abrir el archivo " << archivo << endl;
        return 1;
    }
    cout << "\"" << buscado << "\" aparece " << veces << " vez/veces en " << archivo << "." << endl;
    return 0;
}
