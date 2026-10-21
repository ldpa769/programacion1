// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA..
// Fecha creación: 14/10/2026
// Número de ejercicio: 1

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
using namespace std;

float realAleatorio(float minimo, float maximo) {
    static mt19937 generador(random_device{}());
    uniform_real_distribution<float> distribucion(minimo, maximo);
    return distribucion(generador);
}

int leerCantidad() {
    int N;
    do {
        cout << "Número de corredores: ";
        cin >> N;
    } while (N <= 0);
    return N;
}

// Genera tiempos entre 10.00 y 20.00 segundos
vector<float> generarTiempos(int N) {
    vector<float> tiempos;
    for (int i = 0; i < N; i++) {
        tiempos.push_back(realAleatorio(10.00f, 20.00f));
    }
    return tiempos;
}

void imprimirTiempos(const vector<float>& v, const string& titulo) {
    cout << titulo << endl;
    cout << fixed << setprecision(2);
    for (size_t i = 0; i < v.size(); i++) {
        cout << "  Corredor " << i + 1 << ": " << v[i] << " seg" << endl;
    }
}

// Ordenación por inserción, de menor a mayor
void ordenarInsercion(vector<float>& v) {
    for (size_t i = 1; i < v.size(); i++) {
        float clave = v[i];
        int j = (int)i - 1;
        while (j >= 0 && v[j] > clave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = clave;
    }
}

int main() {
    int N = leerCantidad();
    vector<float> tiempos = generarTiempos(N);
    imprimirTiempos(tiempos, "\nTiempos ANTES de ordenar:");
    ordenarInsercion(tiempos);
    imprimirTiempos(tiempos, "\nTiempos DESPUÉS de ordenar:");
    return 0;
}
