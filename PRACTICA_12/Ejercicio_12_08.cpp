// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyala Arteaga.
// Fecha creación: 16/11/2026
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Conteo {
    int lineas = 0;
    int palabras = 0;
    int caracteres = 0;
};

// Cuenta líneas, palabras y caracteres (incluyendo espacios y saltos de línea).
bool contarArchivo(const string& archivo, Conteo& c) {
    ifstream entrada(archivo);
    if (!entrada) return false;

    bool enPalabra = false;
    char ch;
    while (entrada.get(ch)) {
        c.caracteres++;
        if (ch == '\n') c.lineas++;
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r') {
            enPalabra = false;
        } else if (!enPalabra) {
            enPalabra = true;
            c.palabras++;
        }
    }
    // Si la última línea no termina en salto de línea, también cuenta.
    if (c.caracteres > 0 && ch != '\n') c.lineas++;
    return true;
}

int main() {
    const string archivo = "documento.txt";
    Conteo c;
    if (!contarArchivo(archivo, c)) {
        cout << "No se pudo abrir el archivo " << archivo << endl;
        return 1;
    }
    cout << "Líneas:     " << c.lineas << endl;
    cout << "Palabras:   " << c.palabras << endl;
    cout << "Caracteres: " << c.caracteres << endl;
    return 0;
}
