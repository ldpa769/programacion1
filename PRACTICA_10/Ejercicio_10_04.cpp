// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA..
// Fecha creación: 14/10/2026
// Número de ejercicio: 1
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int leerCantidad() {
    int N;
    do {
        cout << "Número de productos: ";
        cin >> N;
    } while (N <= 0);
    return N;
}

// Lee nombre (una palabra) y precio de cada producto
void leerProductos(vector<string>& productos, vector<double>& precios, int N) {
    for (int i = 0; i < N; i++) {
        string nombre;
        double precio;
        cout << "Producto " << i + 1 << " (nombre): ";
        cin >> nombre;
        do {
            cout << "Precio de " << nombre << ": ";
            cin >> precio;
        } while (precio < 0);
        productos.push_back(nombre);
        precios.push_back(precio);
    }
}

// Ordenación por selección (ascendente). Mueve el nombre junto con su precio.
void ordenarSeleccion(vector<double>& precios, vector<string>& productos) {
    int n = precios.size();
    for (int i = 0; i < n - 1; i++) {
        int posMin = i;
        for (int j = i + 1; j < n; j++) {
            if (precios[j] < precios[posMin]) posMin = j;
        }
        if (posMin != i) {
            double auxP = precios[i];
            precios[i] = precios[posMin];
            precios[posMin] = auxP;
            string auxN = productos[i];
            productos[i] = productos[posMin];
            productos[posMin] = auxN;
        }
    }
}

void mostrarLista(const vector<double>& precios, const vector<string>& productos) {
    cout << "\nPrecios ordenados (ascendente):" << endl;
    for (size_t i = 0; i < precios.size(); i++) {
        cout << "  " << productos[i] << ": " << precios[i] << " Bs" << endl;
    }
}

// Con el vector ya ordenado, el más barato es el primero
void mostrarMasBarato(const vector<double>& precios, const vector<string>& productos) {
    cout << "Producto más barato: " << productos.front()
         << " (" << precios.front() << " Bs)" << endl;
}

// Con el vector ya ordenado, el más caro es el último
void mostrarMasCaro(const vector<double>& precios, const vector<string>& productos) {
    cout << "Producto más caro: " << productos.back()
         << " (" << precios.back() << " Bs)" << endl;
}

// Mediana: valor central (o promedio de los dos centrales si N es par)
void mostrarMediana(const vector<double>& precios) {
    int n = precios.size();
    double mediana;
    if (n % 2 == 1) {
        mediana = precios[n / 2];
    } else {
        mediana = (precios[n / 2 - 1] + precios[n / 2]) / 2.0;
    }
    cout << "Mediana de los precios: " << mediana << " Bs" << endl;
}

int main() {
    cout << fixed << setprecision(2);
    int N = leerCantidad();
    vector<string> productos;
    vector<double> precios;
    leerProductos(productos, precios, N);

    ordenarSeleccion(precios, productos);
    mostrarLista(precios, productos);
    mostrarMasBarato(precios, productos);
    mostrarMasCaro(precios, productos);
    mostrarMediana(precios);
    return 0;
}
