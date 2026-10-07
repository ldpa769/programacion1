// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Segura: >= 8 caracteres, mayuscula, minuscula, numero y caracter especial
bool esSegura(const string& contrasena) {
    if (contrasena.length() < 8) return false;

    bool mayuscula = false, minuscula = false, numero = false, especial = false;
    for (size_t i = 0; i < contrasena.length(); i++) {
        unsigned char c = contrasena[i];
        if (isupper(c)) mayuscula = true;
        else if (islower(c)) minuscula = true;
        else if (isdigit(c)) numero = true;
        else if (!isspace(c)) especial = true;
    }
    return mayuscula && minuscula && numero && especial;
}

int main() {
    string contrasena;
    cout << "Ingrese la contrasena: ";
    getline(cin, contrasena);

    if (esSegura(contrasena)) cout << "Contrasena segura" << endl;
    else cout << "Contrasena vulnerable" << endl;
    return 0;
}
