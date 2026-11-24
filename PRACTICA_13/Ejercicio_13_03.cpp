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

struct Pizza {
    int codigo;
    char nombre[30];
    char tipo[15];     // TRADICIONAL o ESPECIAL
    char tamano[15];   // XS, MEDIANA, GRANDE, FAMILIAR, INTERMINABLE
    double precio;     // precio final (ya incluye el 10% si es ESPECIAL)
};

struct Venta {
    char ci[15];
    int codigo;
    char tamano[15];
    int cantidad;
};

const char* ARCH_PIZZAS = "PRODUCTO.BIN";
const char* ARCH_VENTAS_BIN = "VENTAS_PIZZERIA.BIN";
const char* ARCH_VENTAS_TXT = "VENTAS.TXT";
const double RECARGO_ESPECIAL = 1.10;
const char* TAMANOS[5] = {"XS", "MEDIANA", "GRANDE", "FAMILIAR", "INTERMINABLE"};

template <size_t N>
void copiar(char (&destino)[N], const string& texto) {
    strncpy(destino, texto.c_str(), N - 1);
    destino[N - 1] = '\0';
}

string mayusculas(string s) {
    for (char& c : s) c = toupper(static_cast<unsigned char>(c));
    return s;
}

string recortar(const string& s) {
    size_t i = s.find_first_not_of(" \t\r\n");
    if (i == string::npos) return "";
    size_t j = s.find_last_not_of(" \t\r\n");
    return s.substr(i, j - i + 1);
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

vector<Pizza> cargarPizzas() {
    vector<Pizza> lista;
    ifstream f(ARCH_PIZZAS, ios::binary);
    Pizza p;
    while (f.read(reinterpret_cast<char*>(&p), sizeof(p))) lista.push_back(p);
    return lista;
}

void guardarPizzas(const vector<Pizza>& lista) {
    ofstream f(ARCH_PIZZAS, ios::binary | ios::trunc);
    for (const Pizza& p : lista) f.write(reinterpret_cast<const char*>(&p), sizeof(p));
}

int buscarPizza(const vector<Pizza>& lista, int codigo) {
    for (size_t i = 0; i < lista.size(); i++) {
        if (lista[i].codigo == codigo) return static_cast<int>(i);
    }
    return -1;
}

// Calcula el precio final según el tipo, a partir del precio de la tradicional.
double precioFinal(double precioTradicional, const string& tipo) {
    return tipo == "ESPECIAL" ? precioTradicional * RECARGO_ESPECIAL : precioTradicional;
}

// Elige un tipo de pizza con un menú.
string elegirTipo() {
    while (true) {
        int op = leerEntero("Tipo (1=TRADICIONAL, 2=ESPECIAL): ");
        if (op == 1) return "TRADICIONAL";
        if (op == 2) return "ESPECIAL";
        cout << "Opción inválida." << endl;
    }
}

// Elige un tamaño de pizza con un menú.
string elegirTamano() {
    cout << "Tamaños: ";
    for (int i = 0; i < 5; i++) cout << i + 1 << "=" << TAMANOS[i] << (i < 4 ? ", " : "\n");
    while (true) {
        int op = leerEntero("Tamaño: ");
        if (op >= 1 && op <= 5) return TAMANOS[op - 1];
        cout << "Opción inválida." << endl;
    }
}

void adicionarPizza() {
    vector<Pizza> lista = cargarPizzas();
    int codigo = leerEntero("Código: ");
    if (buscarPizza(lista, codigo) >= 0) {
        cout << "Ya existe una pizza con ese código." << endl;
        return;
    }
    Pizza p{};
    p.codigo = codigo;
    copiar(p.nombre, mayusculas(leerTexto("Nombre: ")));
    string tipo = elegirTipo();
    copiar(p.tipo, tipo);
    copiar(p.tamano, elegirTamano());
    double base = leerReal("Precio de la pizza TRADICIONAL de ese tamaño (Bs): ");
    if (base < 0) {
        cout << "Precio inválido." << endl;
        return;
    }
    p.precio = precioFinal(base, tipo);
    lista.push_back(p);
    guardarPizzas(lista);
    cout << "Pizza agregada. Precio final: " << p.precio << " Bs." << endl;
}

// Suma las pizzas vendidas con ese código en VENTAS.BIN.
int cantidadVendida(int codigo) {
    ifstream f(ARCH_VENTAS_BIN, ios::binary);
    Venta v;
    int total = 0;
    while (f.read(reinterpret_cast<char*>(&v), sizeof(v))) {
        if (v.codigo == codigo) total += v.cantidad;
    }
    return total;
}

void listarPizzas() {
    vector<Pizza> lista = cargarPizzas();
    if (lista.empty()) {
        cout << "No hay pizzas registradas." << endl;
        return;
    }
    cout << "\nLISTADO DE PIZZAS" << endl;
    cout << left << setw(8) << "CODIGO" << setw(16) << "NOMBRE" << setw(13) << "TIPO"
         << setw(14) << "TAMAÑO" << setw(8) << "PRECIO" << setw(10) << "CANTIDAD" << "TOTAL" << endl;
    for (const Pizza& p : lista) {
        int cant = cantidadVendida(p.codigo);
        cout << left << setw(8) << p.codigo << setw(16) << p.nombre << setw(13) << p.tipo
             << setw(14) << p.tamano << setw(8) << p.precio << setw(10) << cant
             << p.precio * cant << endl;
    }
}

void modificarPrecio() {
    vector<Pizza> lista = cargarPizzas();
    int pos = buscarPizza(lista, leerEntero("Código de la pizza: "));
    if (pos < 0) {
        cout << "Pizza no encontrada." << endl;
        return;
    }
    cout << "Precio actual: " << lista[pos].precio << " Bs. (" << lista[pos].tipo << ")" << endl;
    double base = leerReal("Nuevo precio de la TRADICIONAL de ese tamaño (Bs): ");
    if (base < 0) {
        cout << "Precio inválido." << endl;
        return;
    }
    lista[pos].precio = precioFinal(base, lista[pos].tipo);
    guardarPizzas(lista);
    cout << "Nuevo precio: " << lista[pos].precio << " Bs." << endl;
}

void eliminarPizza() {
    vector<Pizza> lista = cargarPizzas();
    int pos = buscarPizza(lista, leerEntero("Código de la pizza a eliminar: "));
    if (pos < 0) {
        cout << "Pizza no encontrada." << endl;
        return;
    }
    lista.erase(lista.begin() + pos);
    guardarPizzas(lista);
    cout << "Pizza eliminada." << endl;
}

// Lee VENTAS.TXT (Carnet; Código; Tamaño; Cantidad) y agrega las ventas a VENTAS.BIN.
void adicionarVentas() {
    ifstream txt(ARCH_VENTAS_TXT);
    if (!txt) {
        cout << "No se encontró el archivo " << ARCH_VENTAS_TXT << endl;
        return;
    }
    vector<Pizza> lista = cargarPizzas();
    ofstream bin(ARCH_VENTAS_BIN, ios::binary | ios::app);
    string linea;
    int agregadas = 0, rechazadas = 0;
    while (getline(txt, linea)) {
        if (recortar(linea).empty()) continue;
        stringstream ss(linea);
        string ci, codStr, tam, cantStr;
        getline(ss, ci, ';');
        getline(ss, codStr, ';');
        getline(ss, tam, ';');
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
        tam = mayusculas(recortar(tam));
        int pos = buscarPizza(lista, codigo);
        if (pos < 0 || tam != lista[pos].tamano || cantidad <= 0) {
            cout << "Venta rechazada (pizza/tamaño no coincide): " << linea << endl;
            rechazadas++;
            continue;
        }
        Venta v{};
        copiar(v.ci, recortar(ci));
        v.codigo = codigo;
        copiar(v.tamano, tam);
        v.cantidad = cantidad;
        bin.write(reinterpret_cast<char*>(&v), sizeof(v));
        agregadas++;
    }
    cout << "Ventas agregadas: " << agregadas << " | rechazadas: " << rechazadas << endl;
}

void mostrarMenu() {
    cout << "\n=== MENU PIZZERIA ELIS ===" << endl;
    cout << "1. Adicionar Pizza" << endl;
    cout << "2. Listado de Pizzas" << endl;
    cout << "3. Modificar el precio de la Pizza según el código" << endl;
    cout << "4. Eliminar una Pizza" << endl;
    cout << "5. Adicionar Venta de Pizzas" << endl;
    cout << "6. Salir" << endl;
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        opcion = leerEntero("Opción: ");
        switch (opcion) {
            case 1: adicionarPizza(); break;
            case 2: listarPizzas(); break;
            case 3: modificarPrecio(); break;
            case 4: eliminarPizza(); break;
            case 5: adicionarVentas(); break;
            case 6: cout << "Hasta luego." << endl; break;
            default: cout << "Opción inválida." << endl;
        }
    } while (opcion != 6);
    return 0;
}
