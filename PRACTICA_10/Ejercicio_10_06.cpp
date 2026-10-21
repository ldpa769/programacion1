// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA..
// Fecha creación: 14/10/2026
// Número de ejercicio: 1
#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

int numeroAleatorio(int minimo, int maximo) {
    static mt19937 generador(random_device{}());
    uniform_int_distribution<int> distribucion(minimo, maximo);
    return distribucion(generador);
}

// Función del ejercicio 1: genera N nombres completos aleatorios
vector<string> generarNombres(const vector<string>& Nombres,
                              const vector<string>& Apellidos, int N) {
    vector<string> resultado;
    for (int i = 0; i < N; i++) {
        int posNombre = numeroAleatorio(0, (int)Nombres.size() - 1);
        int posApellido = numeroAleatorio(0, (int)Apellidos.size() - 1);
        resultado.push_back(Nombres[posNombre] + " " + Apellidos[posApellido]);
    }
    return resultado;
}

// Ordenación por selección, alfabética de la A a la Z
void ordenarAlfabeticamente(vector<string>& lista) {
    int n = lista.size();
    for (int i = 0; i < n - 1; i++) {
        int posMin = i;
        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[posMin]) posMin = j;
        }
        if (posMin != i) {
            string aux = lista[i];
            lista[i] = lista[posMin];
            lista[posMin] = aux;
        }
    }
}

void mostrarLista(const vector<string>& lista, const string& titulo) {
    cout << "\n" << titulo << endl;
    for (size_t i = 0; i < lista.size(); i++) {
        cout << i + 1 << ". " << lista[i] << endl;
    }
}

int leerCantidad() {
    int N;
    do {
        cout << "Número de estudiantes: ";
        cin >> N;
    } while (N <= 0);
    return N;
}

int main() {
    vector<string> Nombres = {"Juan", "María", "Carlos", "Ana", "Luis",
                              "Sofía", "Pedro", "Lucía", "Diego", "Valeria"};
    vector<string> Apellidos = {"Mamani", "Quispe", "Flores", "Rojas", "Condori",
                                "Vargas", "Gutiérrez", "Choque", "Mendoza", "Torrez"};

    int N = leerCantidad();
    vector<string> estudiantes = generarNombres(Nombres, Apellidos, N);
    mostrarLista(estudiantes, "Lista original:");
    ordenarAlfabeticamente(estudiantes);
    mostrarLista(estudiantes, "Lista de asistencia (A-Z):");
    return 0;
}
