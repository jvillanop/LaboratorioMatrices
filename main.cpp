#include <iostream>
#include <ctime>
#include "matrices.h"

using namespace std;

int main() {
    // Inicializar la semilla del generador de números aleatorios
    srand(time(nullptr));

    // Declarar matrices para cada facultad
    float matriz_facultad_1[Matrices::NUMERO_ALUMNOS][Matrices::NUMERO_NOTAS + 1];
    float matriz_facultad_2[Matrices::NUMERO_ALUMNOS][Matrices::NUMERO_NOTAS + 1];
    float matriz_facultad_3[Matrices::NUMERO_ALUMNOS][Matrices::NUMERO_NOTAS + 1];
    char opcion;
    bool repetir = true;

    float promedio_facultad_1;
    float promedio_facultad_2;
    float promedio_facultad_3;
  // Nombres de los alumnos
    string alumnos[Matrices::NUMERO_ALUMNOS] = {"Carlos", "Luis", "Maria", "Pedro", "Juan"};

    // Ciclo principal
    do {
        system("cls");
        promedio_facultad_1 = 0;
        promedio_facultad_2 = 0;
        promedio_facultad_3 = 0;
        cout << "*** Comparativo de Facultades ***" << endl << endl;
               // Llenar y mostrar la matriz para la Facultad de Ingeniería
        Matrices::llenarMatriz(matriz_facultad_1);
        promedio_facultad_1 = Matrices::imprimirMatriz(matriz_facultad_1, alumnos, "Facultad de Ingenieria");

        // Llenar y mostrar la matriz para la Facultad de Arquitectura
        Matrices::llenarMatriz(matriz_facultad_2);
        promedio_facultad_2 = Matrices::imprimirMatriz(matriz_facultad_2, alumnos, "Facultad de Arquitectura");

        // Llenar y mostrar la matriz para la Facultad de Administración
        Matrices::llenarMatriz(matriz_facultad_3);
        promedio_facultad_3 = Matrices::imprimirMatriz(matriz_facultad_3, alumnos, "Facultad de Administracion");

        // Comparar promedios y mostrar la mejor facultad
        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3) {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Ingenieria" << " Promedio: " << promedio_facultad_1 << endl;
        }
        else if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3) {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Arquitectura" << " Promedio: " << promedio_facultad_2 << endl;
        }
        else if (promedio_facultad_3 > promedio_facultad_2 && promedio_facultad_3 > promedio_facultad_1) {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Administracion" << " Promedio: " << promedio_facultad_3 << endl;
        }
        else {
            cout << " Algunas facultades tienen el mismo promedio " << endl << endl;
        }

        // Solicitar al usuario si desea repetir el cálculo
        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n') {
            repetir = false;
        }

    } while (repetir);

    return 0;
}
