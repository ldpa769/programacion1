// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyala Arteaga.
// Fecha creación: 16/11/2026
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Cuenta las palabras (secuencias separadas por espacios o saltos de línea).
// Devuelve -1 si el archivo no se pudo abrir.
int contarPalabras(const string& archivo) {
    ifstream entrada(archivo);
    if (!entrada) return -1;
    int total = 0;
    string palabra;
    while (entrada >> palabra) {
        total++;
    }
    return total;
}

int main() {
    const string archivo = "texto.txt";
    int palabras = contarPalabras(archivo);
    if (palabras < 0) {
        cout << "No se pudo abrir el archivo " << archivo << endl;
        return 1;
    }
    cout << "El archivo " << archivo << " contiene " << palabras << " palabras." << endl;
    return 0;
}
