// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA..
// Fecha creación: 14/10/2026
// Número de ejercicio: 1
#include <iostream>
#include <vector>
#include <random>
using namespace std;

int numeroAleatorio(int minimo, int maximo) {
    static mt19937 generador(random_device{}());
    uniform_int_distribution<int> distribucion(minimo, maximo);
    return distribucion(generador);
}

int leerCantidad() {
    int N;
    do {
        cout << "Número de jugadores: ";
        cin >> N;
    } while (N <= 0);
    return N;
}

// Llena el vector con puntuaciones aleatorias entre 1 y 100
vector<int> generarPuntuaciones(int N) {
    vector<int> puntuaciones;
    for (int i = 0; i < N; i++) {
        puntuaciones.push_back(numeroAleatorio(1, 100));
    }
    return puntuaciones;
}

void mostrarVector(const vector<int>& v, const string& titulo) {
    cout << titulo << ": ";
    for (int x : v) cout << x << " ";
    cout << endl;
}

// Ordena de mayor a menor con el método de la burbuja
void ordenarBurbuja(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] < v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}

// Muestra los 3 primeros lugares (o menos si hay menos jugadores)
void mostrarPodio(const vector<int>& v) {
    string medallas[3] = {"1er lugar", "2do lugar", "3er lugar"};
    int lugares = v.size() < 3 ? (int)v.size() : 3;
    cout << "\n--- PODIO ---" << endl;
    for (int i = 0; i < lugares; i++) {
        cout << medallas[i] << ": " << v[i] << " puntos" << endl;
    }
}

int main() {
    int N = leerCantidad();
    vector<int> puntuaciones = generarPuntuaciones(N);
    mostrarVector(puntuaciones, "Puntuaciones originales");
    ordenarBurbuja(puntuaciones);
    mostrarVector(puntuaciones, "Puntuaciones ordenadas  ");
    mostrarPodio(puntuaciones);
    return 0;
}
