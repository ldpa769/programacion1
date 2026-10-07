// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026

#include <iostream>
#include <string>
using namespace std;

// Separa e imprime protocolo, dominio y ruta de una URL
void analizarURL(const string& url) {
    string protocolo = "", dominio = "", ruta = "/";

    size_t posProtocolo = url.find("://");
    size_t inicioDominio = 0;
    if (posProtocolo != string::npos) {
        protocolo = url.substr(0, posProtocolo);
        inicioDominio = posProtocolo + 3;
    }

    size_t posRuta = url.find('/', inicioDominio);
    if (posRuta == string::npos) {
        dominio = url.substr(inicioDominio);
    } else {
        dominio = url.substr(inicioDominio, posRuta - inicioDominio);
        ruta = url.substr(posRuta);
    }

    cout << "Protocolo: " << protocolo << endl;
    cout << "Dominio: " << dominio << endl;
    cout << "Ruta: " << ruta << endl;
}

int main() {
    string url;
    cout << "Ingrese la URL: ";
    getline(cin, url);
    analizarURL(url);
    return 0;
}
