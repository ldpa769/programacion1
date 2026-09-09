// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 09/09/2026
// Número de ejercicio: 4

#include <iostream>
using namespace std;

// Area de un cuadrado
double calcularArea(double lado){
    return lado * lado;
}

// Area de un rectangulo
double calcularArea(double base, double altura){
    return base * altura;
}

// Area de un circulo
float calcularArea(float radio, float PI){
    return PI * radio * radio;
}

int main(){
    double lado, base, altura;
    float radio, PI = 3.1416f;

    cout << "--- Area de un cuadrado ---" << endl;
    cout << "Ingrese el lado: ";
    cin >> lado;
    cout << "Area = " << calcularArea(lado) << endl;

    cout << "\n--- Area de un rectangulo ---" << endl;
    cout << "Ingrese base y altura: ";
    cin >> base >> altura;
    cout << "Area = " << calcularArea(base, altura) << endl;

    cout << "\n--- Area de un circulo ---" << endl;
    cout << "Ingrese el radio: ";
    cin >> radio;
    cout << "Area = " << calcularArea(radio, PI) << endl;

    return 0;
}
