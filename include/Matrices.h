#ifndef MATRICES_H
#define MATRICES_H

#include <string>

class Matrices {
public:
     // Constantes para el tamaño de la matriz y rangos de calificación
    static const int NUMERO_ALUMNOS = 5;
    static const int NUMERO_MATERIAS = 5;
    static const int NUMERO_NOTAS = 4;
    static const int MAX_CALIFICACION = 100;
    static const int MIN_CALIFICACION = 0;
    static const int MAXIMA_LONGITUD_CADENA = 100;

    // Funciones para generar y manipular matrices
    static int busquedaAleatorios(int minimo, int maximo);
    static void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]);
    static void imprimirMatrizLinea();
    static float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], std::string alumnos[NUMERO_ALUMNOS], std::string nombreFacultad);
};

#endif // MATRICES_H
