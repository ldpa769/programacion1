// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del estudiante: ING MECATRONICA.
// Fecha creación: 04/11/2026

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Contacto {
    string nombreCompleto;
    int telefono;
};

void registrarContactos(vector<Contacto>& contactos, int n) {
    for (int i = 0; i < n; i++) {
        Contacto c;
        cout << "\nContacto " << i + 1 << endl;
        cout << "Nombre completo: ";
        getline(cin, c.nombreCompleto);
        cout << "Teléfono: ";
        cin >> c.telefono;
        cin.ignore();
        contactos.push_back(c);
    }
}

void buscarContactos(const vector<Contacto>& contactos, const string& busqueda) {
    bool encontrado = false;
    cout << "\nResultados para \"" << busqueda << "\":" << endl;
    for (const Contacto& c : contactos) {
        if (c.nombreCompleto.find(busqueda) != string::npos) {
            cout << c.nombreCompleto << " - " << c.telefono << endl;
            encontrado = true;
        }
    }
    if (!encontrado) cout << "No se encontraron contactos." << endl;
}

int main() {
    int n;
    cout << "¿Cuántos contactos desea registrar? ";
    cin >> n;
    cin.ignore();

    vector<Contacto> contactos;
    registrarContactos(contactos, n);

    string busqueda;
    cout << "\nTexto a buscar: ";
    getline(cin, busqueda);
    buscarContactos(contactos, busqueda);
    return 0;
}
