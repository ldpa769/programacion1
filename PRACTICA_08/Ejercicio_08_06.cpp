// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026

#include <iostream>
#include <string>
using namespace std;

// Quita espacios al inicio y final, y reduce espacios repetidos a uno solo
string limpiarEspacios(const string& texto) {
    string resultado = "";
    bool espacioPendiente = false;

    for (size_t i = 0; i < texto.length(); i++) {
        if (texto[i] == ' ') {
            if (!resultado.empty()) espacioPendiente = true;  // ignora espacios iniciales
        } else {
            if (espacioPendiente) {
                resultado += ' ';
                espacioPendiente = false;
            }
            resultado += texto[i];
        }
    }
    return resultado;   // los espacios finales nunca se agregan
}

int main() {
    string texto;
    cout << "Ingrese el texto: ";
    getline(cin, texto);

    cout << "Salida: \"" << limpiarEspacios(texto) << "\"" << endl;
    return 0;
}
