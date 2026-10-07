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

// Devuelve los contactos que empiezan con el prefijo (ignora mayusculas)
vector<string> buscarContactos(const vector<string>& contactos, const string& prefijo) {
    vector<string> resultado;
    string pref = aMinuscula(prefijo);
    for (size_t i = 0; i < contactos.size(); i++) {
        if (aMinuscula(contactos[i]).substr(0, pref.length()) == pref)
            resultado.push_back(contactos[i]);
    }
    return resultado;
}

void imprimirResultados(const vector<string>& resultado) {
    cout << "Resultados: ";
    if (resultado.empty()) cout << "(sin coincidencias)";
    for (size_t i = 0; i < resultado.size(); i++) {
        cout << resultado[i];
        if (i + 1 < resultado.size()) cout << ", ";
    }
    cout << endl;
}

int main() {
    vector<string> contactos = {"Marcelo", "Maria", "Martin", "Juan", "Marcos"};
    string prefijo;
    cout << "Prefijo de busqueda: ";
    getline(cin, prefijo);

    imprimirResultados(buscarContactos(contactos, prefijo));
    return 0;
}
