// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;

string aMinuscula(string s) {
    for (size_t i = 0; i < s.length(); i++) s[i] = tolower((unsigned char)s[i]);
    return s;
}

// Divide una oracion en palabras
vector<string> dividirPalabras(const string& oracion) {
    vector<string> palabras;
    istringstream flujo(oracion);
    string palabra;
    while (flujo >> palabra) palabras.push_back(palabra);
    return palabras;
}

// Cuenta cuantas palabras de A estan tambien en B. true si coinciden mas de 3.
bool sospechaPlagio(const string& a, const string& b, vector<string>& coincidencias) {
    vector<string> palabrasA = dividirPalabras(a);
    vector<string> palabrasB = dividirPalabras(b);

    for (size_t i = 0; i < palabrasA.size(); i++) {
        for (size_t j = 0; j < palabrasB.size(); j++) {
            if (aMinuscula(palabrasA[i]) == aMinuscula(palabrasB[j])) {
                coincidencias.push_back(palabrasA[i]);
                break;
            }
        }
    }
    return coincidencias.size() > 3;
}

int main() {
    string a, b;
    cout << "Oracion A: ";
    getline(cin, a);
    cout << "Oracion B: ";
    getline(cin, b);

    vector<string> coincidencias;
    bool plagio = sospechaPlagio(a, b, coincidencias);

    cout << "Alerta de plagio: " << (plagio ? "Verdadero" : "Falso");
    cout << " (coinciden ";
    for (size_t i = 0; i < coincidencias.size(); i++) {
        cout << "\"" << coincidencias[i] << "\"";
        if (i + 1 < coincidencias.size()) cout << ", ";
    }
    cout << ")" << endl;
    return 0;
}
