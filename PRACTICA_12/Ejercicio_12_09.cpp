// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyala Arteaga.
// Fecha creación: 16/11/2026
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Desplaza una letra 'desplazamiento' posiciones; los demás caracteres no cambian.
char cifrarCaracter(char c, int desplazamiento) {
    if (c >= 'A' && c <= 'Z') return 'A' + (c - 'A' + desplazamiento) % 26;
    if (c >= 'a' && c <= 'z') return 'a' + (c - 'a' + desplazamiento) % 26;
    return c;
}

// Cifra una línea completa.
string cifrarLinea(const string& linea, int desplazamiento) {
    string resultado = linea;
    for (char& c : resultado) {
        c = cifrarCaracter(c, desplazamiento);
    }
    return resultado;
}

// Cifra todo el archivo de entrada y lo guarda en el de salida.
bool cifrarArchivo(const string& entradaNombre, const string& salidaNombre, int desplazamiento) {
    ifstream entrada(entradaNombre);
    if (!entrada) return false;
    ofstream salida(salidaNombre);
    if (!salida) return false;

    string linea;
    while (getline(entrada, linea)) {
        salida << cifrarLinea(linea, desplazamiento) << '\n';
    }
    return true;
}

int main() {
    if (!cifrarArchivo("mensaje.txt", "mensaje_cifrado.txt", 3)) {
        cout << "No se pudo abrir mensaje.txt o crear mensaje_cifrado.txt" << endl;
        return 1;
    }
    cout << "Mensaje cifrado guardado en mensaje_cifrado.txt" << endl;
    return 0;
}
