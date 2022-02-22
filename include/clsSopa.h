////#############################################################################
// ARCHIVO : clsSopa.h
// AUTOR : Mauricio Molina, Maximiliano Fernandez
// FECHA DE CREACION : 10/10/2018.
// ULTIMA ACTUALIZACION: 14/11/2018.
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO : Linux (Ubuntu) / Windows XP / Windows 7.
// IDE : Code::Blocks - 8.02 / 10.05
// COMPILADOR : GNU GCC Compiler (Linux) / MinGW (Windows).
// LICENCIA : GPL (General Public License) - Version 3.
//=============================================================================
// DESCRIPCION:
// metodos y atributos de la clase clsSopa
/////////////////////////////////////////////////////////////////////////////////

#ifndef CLSSOPA_H
#define CLSSOPA_H

#include <clsError.h>
#include <clsRandom.h>

#include "clsPalabra.h"

typedef enum {
    eNada,
    eLetra,
    ePalabra,
    eJuego
} Resultado;

class clsSopa
{
private:
    clsPalabra *palabras;       // vector de palabras
    char **letras;              // matriz de letras
    int **posiciones;           // matriz de posiciones

    int tam;                    // tamaño de la matriz cuadrada
    int cant;                   // cantidad de palabras

    clsError error;
    clsRandom random;

    bool ubicar(int pos);
    bool verificarPosicion(int i, int j);
    bool verificarFinal();
    void crearMatrizLetras();
    void crearMatrizPosiciones();

public:
    int getTam() { return tam; }
    int init(char *lista[], int cant);
    char get(int i, int j) { return letras[i][j]; }
    Resultado clic(int i, int j, clsPalabra **palabra);
};

#endif // CLSSOPA_H
