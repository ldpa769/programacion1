// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyala Arteaga.
// Fecha creación: 16/11/2026
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Producto {
    string nombre;
    double precio;
};

const string ARCHIVO = "productos.txt";

// Si el archivo no existe, lo crea con datos de ejemplo.
void crearEjemploSiNoExiste() {
    ifstream prueba(ARCHIVO);
    if (prueba) return;
    ofstream salida(ARCHIVO);
    salida << "Manzana 1.50\nPera 2.00\nPlatano 0.80\n";
}

// Carga los productos del archivo. El precio es la última palabra de la línea.
vector<Producto> cargarProductos() {
    vector<Producto> lista;
    ifstream entrada(ARCHIVO);
    string linea;
    while (getline(entrada, linea)) {
        size_t pos = linea.rfind(' ');
        if (pos == string::npos) continue;
        Producto p;
        p.nombre = linea.substr(0, pos);
        try {
            p.precio = stod(linea.substr(pos + 1));
        } catch (...) {
            continue;
        }
        lista.push_back(p);
    }
    return lista;
}

// Reescribe el archivo con la lista actualizada.
void guardarProductos(const vector<Producto>& lista) {
    ofstream salida(ARCHIVO);
    for (const Producto& p : lista) {
        salida << p.nombre << ' ' << fixed << setprecision(2) << p.precio << '\n';
    }
}

// Busca el producto (sin distinguir mayúsculas) y devuelve su posición o -1.
int buscarProducto(const vector<Producto>& lista, const string& nombre) {
    auto minusculas = [](string s) {
        for (char& c : s) c = tolower(static_cast<unsigned char>(c));
        return s;
    };
    for (size_t i = 0; i < lista.size(); i++) {
        if (minusculas(lista[i].nombre) == minusculas(nombre)) return static_cast<int>(i);
    }
    return -1;
}

void mostrarProductos(const vector<Producto>& lista) {
    cout << "\n--- Productos ---" << endl;
    for (const Producto& p : lista) {
        cout << left << setw(20) << p.nombre << fixed << setprecision(2) << p.precio << endl;
    }
}

int main() {
    crearEjemploSiNoExiste();
    vector<Producto> lista = cargarProductos();
    mostrarProductos(lista);

    string nombre;
    cout << "\nProducto a actualizar: ";
    getline(cin, nombre);

    int pos = buscarProducto(lista, nombre);
    if (pos < 0) {
        cout << "El producto \"" << nombre << "\" no existe." << endl;
        return 0;
    }

    double nuevo;
    cout << "Nuevo precio: ";
    if (!(cin >> nuevo) || nuevo < 0) {
        cout << "Precio inválido." << endl;
        return 1;
    }
    lista[pos].precio = nuevo;
    guardarProductos(lista);
    cout << "Precio actualizado." << endl;
    mostrarProductos(lista);
    return 0;
}
