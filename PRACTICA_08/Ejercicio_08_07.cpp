// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// Extrae todas las palabras que comienzan con '#'
vector<string> extraerHashtags(const string& texto) {
    vector<string> etiquetas;
    size_t i = 0;
    while (i < texto.length()) {
        if (texto[i] == '#') {
            size_t j = i + 1;
            while (j < texto.length() &&
                   (isalnum((unsigned char)texto[j]) || texto[j] == '_')) j++;
            if (j > i + 1) etiquetas.push_back(texto.substr(i, j - i));
            i = j;
        } else {
            i++;
        }
    }
    return etiquetas;
}

void mostrarHashtags(const vector<string>& etiquetas) {
    cout << "Lista de hashtags: [";
    for (size_t i = 0; i < etiquetas.size(); i++) {
        cout << etiquetas[i];
        if (i + 1 < etiquetas.size()) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    string texto;
    cout << "Ingrese el tweet: ";
    getline(cin, texto);
    mostrarHashtags(extraerHashtags(texto));
    return 0;
}
