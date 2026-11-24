// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyala Arteaga.
// Fecha creación: 16/11/2026
// Número de ejercicio: 1

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

struct Producto {
    int codigo;
    char nombre[40];
    int cantidadInicial;
    double precio;
};

struct Venta {
    char ci[15];
    char cliente[40];
    int codigo;
    int cantidad;
};

const char* ARCH_PROD = "PRODUCTOS.BIN";
const char* ARCH_VENTAS_BIN = "VENTAS_FARMACIA.BIN";
const char* ARCH_VENTAS_TXT = "VENTAS.txt";

template <size_t N>
void copiar(char (&destino)[N], const string& texto) {
    strncpy(destino, texto.c_str(), N - 1);
    destino[N - 1] = '\0';
}

string leerTexto(const string& mensaje) {
    string t;
    cout << mensaje;
    getline(cin, t);
    return t;
}

int leerEntero(const string& mensaje) {
    while (true) {
        string linea = leerTexto(mensaje);
        try {
            size_t pos;
            int v = stoi(linea, &pos);
            if (pos == linea.size()) return v;
        } catch (...) {}
        cout << "Valor inválido, intente de nuevo." << endl;
    }
}

double leerReal(const string& mensaje) {
    while (true) {
        string linea = leerTexto(mensaje);
        try {
            size_t pos;
            double v = stod(linea, &pos);
            if (pos == linea.size()) return v;
        } catch (...) {}
        cout << "Valor inválido, intente de nuevo." << endl;
    }
}

string recortar(const string& s) {
    size_t i = s.find_first_not_of(" \t\r\n");
    if (i == string::npos) return "";
    size_t j = s.find_last_not_of(" \t\r\n");
    return s.substr(i, j - i + 1);
}

// Devuelve la posición (índice de registro) del producto o -1 si no existe.
int buscarPosicion(int codigo, Producto& encontrado) {
    ifstream f(ARCH_PROD, ios::binary);
    Producto p;
    int pos = 0;
    while (f.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        if (p.codigo == codigo) {
            encontrado = p;
            return pos;
        }
        pos++;
    }
    return -1;
}

// Suma las cantidades vendidas de un producto en VENTAS.BIN.
int cantidadVendida(int codigo) {
    ifstream f(ARCH_VENTAS_BIN, ios::binary);
    Venta v;
    int total = 0;
    while (f.read(reinterpret_cast<char*>(&v), sizeof(v))) {
        if (v.codigo == codigo) total += v.cantidad;
    }
    return total;
}

void adicionarProducto() {
    Producto p{};
    p.codigo = leerEntero("Código: ");
    Producto aux;
    if (buscarPosicion(p.codigo, aux) >= 0) {
        cout << "Ya existe un producto con ese código." << endl;
        return;
    }
    copiar(p.nombre, leerTexto("Nombre: "));
    p.cantidadInicial = leerEntero("Cantidad inicial: ");
    p.precio = leerReal("Precio unitario: ");
    if (p.cantidadInicial < 0 || p.precio < 0) {
        cout << "Datos inválidos." << endl;
        return;
    }
    ofstream f(ARCH_PROD, ios::binary | ios::app);
    f.write(reinterpret_cast<char*>(&p), sizeof(p));
    cout << "Producto agregado." << endl;
}

void listarProductos() {
    ifstream f(ARCH_PROD, ios::binary);
    if (!f) {
        cout << "No hay productos registrados." << endl;
        return;
    }
    cout << "\n" << left << setw(8) << "CODIGO" << setw(22) << "NOMBRE PRODUCTO"
         << setw(18) << "CANTIDAD INICIAL" << setw(10) << "PRECIO"
         << setw(18) << "CANTIDAD VENDIDA" << "TOTAL" << endl;
    Producto p;
    while (f.read(reinterpret_cast<char*>(&p), sizeof(p))) {
        int vendida = cantidadVendida(p.codigo);
        cout << left << setw(8) << p.codigo << setw(22) << p.nombre
             << setw(18) << p.cantidadInicial << setw(10) << p.precio
             << setw(18) << vendida << p.precio * vendida << endl;
    }
}

void buscarProducto() {
    int codigo = leerEntero("Código a buscar: ");
    Producto p;
    if (buscarPosicion(codigo, p) < 0) {
        cout << "Producto no encontrado." << endl;
        return;
    }
    cout << "Código: " << p.codigo << "\nNombre: " << p.nombre
         << "\nCantidad inicial: " << p.cantidadInicial
         << "\nPrecio: " << p.precio << endl;
}

void modificarProducto() {
    int codigo = leerEntero("Código del producto a modificar: ");
    Producto p;
    int pos = buscarPosicion(codigo, p);
    if (pos < 0) {
        cout << "Producto no encontrado." << endl;
        return;
    }
    cout << "Actual: " << p.nombre << " | cantidad " << p.cantidadInicial
         << " | precio " << p.precio << endl;
    copiar(p.nombre, leerTexto("Nuevo nombre: "));
    p.cantidadInicial = leerEntero("Nueva cantidad inicial: ");
    p.precio = leerReal("Nuevo precio: ");

    fstream f(ARCH_PROD, ios::binary | ios::in | ios::out);
    f.seekp(static_cast<streamoff>(pos) * sizeof(Producto));
    f.write(reinterpret_cast<char*>(&p), sizeof(p));
    cout << "Producto modificado." << endl;
}

// Lee VENTAS.txt (CI; Cliente; Código; Cantidad) y agrega las ventas a VENTAS.BIN.
void adicionarVentas() {
    ifstream txt(ARCH_VENTAS_TXT);
    if (!txt) {
        cout << "No se encontró el archivo " << ARCH_VENTAS_TXT << endl;
        return;
    }
    ofstream bin(ARCH_VENTAS_BIN, ios::binary | ios::app);
    string linea;
    int agregadas = 0, rechazadas = 0;
    while (getline(txt, linea)) {
        if (recortar(linea).empty()) continue;
        stringstream ss(linea);
        string ci, cliente, codStr, cantStr;
        getline(ss, ci, ';');
        getline(ss, cliente, ';');
        getline(ss, codStr, ';');
        getline(ss, cantStr, ';');
        int codigo, cantidad;
        try {
            codigo = stoi(recortar(codStr));
            cantidad = stoi(recortar(cantStr));
        } catch (...) {
            cout << "Línea inválida: " << linea << endl;
            rechazadas++;
            continue;
        }
        Producto p;
        if (buscarPosicion(codigo, p) < 0) {
            cout << "Producto " << codigo << " no existe. Venta rechazada: " << linea << endl;
            rechazadas++;
            continue;
        }
        if (cantidad <= 0 || cantidadVendida(codigo) + cantidad > p.cantidadInicial) {
            cout << "Stock insuficiente o cantidad inválida. Venta rechazada: " << linea << endl;
            rechazadas++;
            continue;
        }
        Venta v{};
        copiar(v.ci, recortar(ci));
        copiar(v.cliente, recortar(cliente));
        v.codigo = codigo;
        v.cantidad = cantidad;
        bin.write(reinterpret_cast<char*>(&v), sizeof(v));
        bin.flush();
        agregadas++;
    }
    cout << "Ventas agregadas: " << agregadas << " | rechazadas: " << rechazadas << endl;
}

void mostrarMenu() {
    cout << "\n=== MENU FARMACIAS CHAVEZ ===" << endl;
    cout << "1. Adicionar Producto" << endl;
    cout << "2. Listado de Productos" << endl;
    cout << "3. Buscar un producto por código" << endl;
    cout << "4. Modificar un producto" << endl;
    cout << "5. Adicionar ventas del producto" << endl;
    cout << "6. Salir" << endl;
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        opcion = leerEntero("Opción: ");
        switch (opcion) {
            case 1: adicionarProducto(); break;
            case 2: listarProductos(); break;
            case 3: buscarProducto(); break;
            case 4: modificarProducto(); break;
            case 5: adicionarVentas(); break;
            case 6: cout << "Hasta luego." << endl; break;
            default: cout << "Opción inválida." << endl;
        }
    } while (opcion != 6);
    return 0;
}
