#include "matrices.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para generar números aleatorios en un rango dado
int Matrices::busquedaAleatorios(int minimo, int maximo) {
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

// Función para llenar la matriz con calificaciones aleatorias
void Matrices::llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]) {
    int y, x;
    for (y = 0; y < NUMERO_ALUMNOS; y++) {
        float suma = 0;
        int calificacion = 0;
        for (x = 0; x < NUMERO_NOTAS; x++) {
            // Se generan calificaciones aleatorias para los distintos tipos de notas
            if (x == 0 || x == 3)  //primer parcial
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 20);
            }
            else if (x == 1)  //segundo parcial
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 25);
            }
            else if (x == 2)  //examen final
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 35);
            }
            suma += static_cast<float>(calificacion);
            matriz[y][x] = calificacion;
            calificacion = 0;
        }
            // Agregar promedio al final de cada fila
        matriz[y][NUMERO_NOTAS] = suma;
    }
}

// Función para imprimir una línea separadora en la matriz
void Matrices::imprimirMatrizLinea() {
    int x;
    cout << "+--------";
    for (x = 0; x < NUMERO_NOTAS + 1; x++) {
        cout << "+---------";
    }
    cout << "+\n";
}

// Función para imprimir la matriz de calificaciones junto con sus promedios
float Matrices::imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], string alumnos[NUMERO_ALUMNOS], string nombreFacultad) {
    int y, x;
    float promedioMayor = matriz[0][NUMERO_NOTAS];
    float promedioMenor = matriz[0][NUMERO_NOTAS];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char alumnoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, alumnos[0].c_str(), MAXIMA_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, alumnos[0].c_str(), MAXIMA_LONGITUD_CADENA);
    cout << nombreFacultad << endl;
    cout << "(Nota1)=>Primer Parcial  (Nota2)=>Segundo Parcial (Nota3)=>Final (Nota4)=>Actividades" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Alumno";
    for (x = 0; x < NUMERO_NOTAS; x++) {
        cout << setw(9) << "Nota" << x + 1;
    }
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < NUMERO_ALUMNOS; y++) {
        cout << "!" << setw(8) << alumnos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_NOTAS; x++) {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "!";
        }
        float promedio = matriz[y][NUMERO_NOTAS];
        totalGeneral += matriz[y][NUMERO_NOTAS];
        if (promedio > promedioMayor) {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, alumnos[y].c_str(), MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor) {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, alumnos[y].c_str(), MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }

     // Calcular promedio general
    promedioGeneral = totalGeneral / NUMERO_ALUMNOS;
    cout << "Nota mayor: " << setw(10) << alumnoPromedioMayor << setw(10) << promedioMayor << endl;
    cout << "Nota menor: " << setw(10) << alumnoPromedioMenor << setw(10) << promedioMenor << endl;
    cout << "Nota prom : " << setw(10) << promedioGeneral << endl << endl;
    return promedioGeneral;
}
