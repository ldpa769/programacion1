// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del estudiante: ING MECATRONICA.
// Fecha creación: 04/11/2026

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Producto {
    string nombre;
    string codigo;
    double precio;
};

void registrarProductos(vector<Producto>& productos, int n) {
    for (int i = 0; i < n; i++) {
        Producto p;
        cout << "\nProducto " << i + 1 << endl;
        cout << "Nombre: ";
        getline(cin, p.nombre);
        cout << "Código: ";
        getline(cin, p.codigo);
        cout << "Precio: ";
        cin >> p.precio;
        cin.ignore();
        productos.push_back(p);
    }
}

void masCaroYMasBarato(const vector<Producto>& productos) {
    if (productos.empty()) {
        cout << "No hay productos." << endl;
        return;
    }
    const Producto* caro = &productos[0];
    const Producto* barato = &productos[0];
    for (const Producto& p : productos) {
        if (p.precio > caro->precio) caro = &p;
        if (p.precio < barato->precio) barato = &p;
    }
    cout << "\nMás caro:   " << caro->nombre << " - " << caro->precio << endl;
    cout << "Más barato: " << barato->nombre << " - " << barato->precio << endl;
}

int main() {
    int n;
    cout << "¿Cuántos productos desea ingresar? ";
    cin >> n;
    cin.ignore();

    vector<Producto> productos;
    registrarProductos(productos, n);
    masCaroYMasBarato(productos);
    return 0;
}
