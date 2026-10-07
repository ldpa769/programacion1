// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string aMinuscula(string s) {
    for (size_t i = 0; i < s.length(); i++) s[i] = tolower((unsigned char)s[i]);
    return s;
}

// Reemplaza cada palabra prohibida (sin importar mayusculas) por ***
string censurar(string mensaje, const vector<string>& prohibidas) {
    for (size_t k = 0; k < prohibidas.size(); k++) {
        string palabra = aMinuscula(prohibidas[k]);
        if (palabra.empty()) continue;

        size_t pos = aMinuscula(mensaje).find(palabra);
        while (pos != string::npos) {
            mensaje.replace(pos, palabra.length(), "***");
            pos = aMinuscula(mensaje).find(palabra, pos + 3);
        }
    }
    return mensaje;
}

int main() {
    vector<string> prohibidas = {"tonto", "manco", "noob"};
    string mensaje;
    cout << "Mensaje del jugador: ";
    getline(cin, mensaje);

    cout << "Salida: " << censurar(mensaje, prohibidas) << endl;
    return 0;
}
