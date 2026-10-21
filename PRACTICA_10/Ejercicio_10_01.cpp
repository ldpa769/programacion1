// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA..
// Fecha creación: 14/10/2026
// Número de ejercicio: 1

#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;

// Devuelve un entero aleatorio en el rango [minimo, maximo]
int numeroAleatorio(int minimo, int maximo) {
    static mt19937 generador(random_device{}());
    uniform_int_distribution<int> distribucion(minimo, maximo);
    return distribucion(generador);
}

// Genera N nombres completos combinando al azar un nombre y un apellido
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

void mostrarNombres(const vector<string>& lista) {
    for (size_t i = 0; i < lista.size(); i++) {
        cout << i + 1 << ". " << lista[i] << endl;
    }
}

int leerCantidad() {
    int N;
    do {
        cout << "¿Cuántos nombres desea generar? ";
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
    vector<string> completos = generarNombres(Nombres, Apellidos, N);
    mostrarNombres(completos);
    return 0;
}
