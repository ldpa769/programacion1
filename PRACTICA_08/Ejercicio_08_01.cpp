// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Elige al azar un nombre, un apellido y una edad y los muestra
void mostrarPersonaAleatoria(const vector<string>& nombres,
                             const vector<string>& apellidos,
                             const vector<int>& edades) {
    string nombre = nombres[rand() % nombres.size()];
    string apellido = apellidos[rand() % apellidos.size()];
    int edad = edades[rand() % edades.size()];
    cout << nombre << " " << apellido << ", " << edad << " anios" << endl;
}

int main() {
    srand((unsigned)time(0));

    vector<string> nombres = {"Juan", "Maria", "Carlos", "Ana", "Luis",
                              "Sofia", "Pedro", "Lucia", "Diego", "Valeria"};
    vector<string> apellidos = {"Perez", "Gonzalez", "Rojas", "Mamani", "Quispe",
                                "Flores", "Vargas", "Choque", "Condori", "Salazar"};
    vector<int> edades = {18, 19, 20, 21, 22, 23, 25, 28, 30, 35};

    int n;
    cout << "Cuantas personas desea generar (N)? ";
    cin >> n;
    for (int i = 0; i < n; i++) mostrarPersonaAleatoria(nombres, apellidos, edades);
    return 0;
}
