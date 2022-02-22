////#############################################################################
// ARCHIVO : clsSopa.cpp
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
// crea las matrices de letras y de posiciones, verifica las posiciones y ubica las palabras
/////////////////////////////////////////////////////////////////////////////////

#include "clsSopa.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

//*****************************************************************************
// DEFINICION DE LOS METODOS
//=============================================================================
// FUNCION : int clsSopa::init(char *lista[], int cant)
// ACCION : Determina el tamaño necesario de la matriz para ubicar la
// palabra más larga con algún margen, por eso se le suma 4
// PARAMETROS: (char *lista[], int cant)
// DEVUELVE :  int return 0
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int clsSopa::init(char *lista[], int cant) {

    random.init();
    this->cant = cant;

    // Determina el tamaño necesario de la matriz para ubicar la palabra más larga con algún margen
    tam = 0;
    for (int i = 0; i < cant; i++) {
        int l = strlen(lista[i]);
        if(l > tam) {
            tam = l;
        }
    }
    tam += 4;

    crearMatrizPosiciones();
    crearMatrizLetras();

    // Crea e inicializa el vector de palabras y su cantidad
        palabras = new clsPalabra[cant];
       for (int i = 0; i < cant; i++) {
        palabras[i].init(lista[i]);
    }

    // Ordena las palabras por tamaño decreciente para optimizar la ubicación en la grilla
    bool cambio;
    int c = cant;
    do {
        cambio = false;
        for(int i = 1; i < c; i++) {
            if(palabras[i].largo > palabras[i-1].largo) {
                clsPalabra aux = palabras[i];
                palabras[i] = palabras[i-1];
                palabras[i-1] = aux;
                cambio = true;
            }
        }
        c--;
    } while(cambio);

    // Finalmente ubica las palabras
    for(int i = 0; i < cant; i++) {
        while(!ubicar(i));        // intenta ubicar la palabra hasta que lo logra
    }
    // completa la grilla con letras aletorias
    for(int i = 0; i < tam; i++) {
        for(int j = 0; j < tam; j++) {
            if(letras[i][j] <= 0) {     // si la posición no contiene una letra ubicada
                if(letras[i][j] == 0) {
                    letras[i][j] = rand() % ('Z' - 'A' + 1) + 'A'; // letras al azar entre 'A' y 'Z'
                } else {
                    letras[i][j] = -letras[i][j];                  // le quita la marca de provisoria
                }
            }
        }
    }

    return 0;
}

//=============================================================================
// FUNCION : bool clsSopa::ubicar(int pos)
// ACCION : Se encarga de ubicar las palabras al azar,
// si ubicó la palabra con éxito inicializa su posición y su dirección
// PARAMETROS: (int pos)
// DEVUELVE :  bool si tuvo exito o no
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool clsSopa::ubicar(int pos) {
    clsPalabra *pal = &palabras[pos];
    cout << "Ubicando [" << pos << "] " << pal->palabra << endl;

    int largo = pal->largo;
    int i, j;
    int di, dj;

    // determina al azar las coordenadas de inicio
    i = random.getNumber(tam);
    j = random.getNumber(tam);

    // determina al azar las direcciones vertical y horizontal
    do {
        di = random.getNumber(3) - 1;
        dj = random.getNumber(3) - 1;
    } while(!(di || dj));   // no pueden ser ambas nulas

    int f, c;           // coordenedas de fila y columna

    f = i;
    c = j;

    bool exito = true;
    // intenta ubicar cada letra de la palabra
    for(int p = 0; p < largo && exito; p++) {
        exito = verificarPosicion(f, c);
        if(exito) {
            letras[f][c] = -pal->palabra[p]; // marca la posición provisoriamente con la letra enmascarada
            f += di;
            c += dj;
        }
    }

    // si ubicó la palabra con éxito inicializa su posición y su dirección
    if(exito) {
        pal->i = i;
        pal->j = j;
        pal->di = di;
        pal->dj = dj;

        f = i;
        c = j;
        for(int p = 0; p < largo; p++) {
            letras[f][c] = pal->palabra[p];     // desenmascara la letra para dejarla como definitiva
            posiciones[f][c] = pos;             // inicializa la matriz de posiciones con el índice de la palabra
            f += di;
            c += dj;
        }
    }

    return exito;
}


//=============================================================================
// FUNCION : bool clsSopa::verificarPosicion(int i, int j)
// ACCION : verifico la posicion donde se colocaran las letras
// PARAMETROS: (int i, int j)
// DEVUELVE :  bool si las coloca
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool clsSopa::verificarPosicion(int i, int j) {
    return  i >= 0 && i < tam && j >= 0 && j < tam && letras[i][j] <= 0;
}


//=============================================================================
// FUNCION : Resultado clsSopa::clic(int i, int j, clsPalabra **palabra)
// ACCION : detecta cuando se van descontando cada letra de la palabra, es decir
// por click a la palabra se le descuenta 1 cuando queda en 0 es palabra completa
// PARAMETROS:  (int i, int j, clsPalabra **palabra)
// DEVUELVE :  Resultado
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Resultado clsSopa::clic(int i, int j, clsPalabra **palabra) {
    int pos = posiciones[i][j];
    bool acerto = pos >= 0;
    Resultado resultado;
    *palabra = NULL;

    if(acerto) {
        palabras[pos].clics--;
        posiciones[i][j] = -1;

        if(palabras[pos].clics) {
            resultado = eLetra;
        } else {
            *palabra = &palabras[pos];
            if(verificarFinal()) {
                resultado = eJuego;
            } else {
                resultado = ePalabra;
            }
        }
    } else {
        resultado = eNada;
    }

    return resultado;
}


//=============================================================================
// FUNCION : bool clsSopa::verificarFinal()
// ACCION : Retorna true si todas las palabras han sido completadas
// PARAMETROS:  ()
// DEVUELVE :  bool, true si todas las palabras fueron completadas
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool clsSopa::verificarFinal() {
    int i;
    // Bsca una palabra que no haya sido completada
    for(i = 0; i < cant && !palabras[i].clics; i++);
    // Si llegó al final es porque todas están completas y el juego llegó al final
    return i == cant;
}


//=============================================================================
// FUNCION : void clsSopa::crearMatrizLetras()
// ACCION :  Crea la matriz de letras y la inicializa con ceros
// PARAMETROS:  ()
// DEVUELVE :  void NADA
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

void clsSopa::crearMatrizLetras() {
    letras = new char*[tam];
    for(int i = 0; i < tam; i++) {
        letras[i] = new char[tam];
        for(int j = 0; j < tam; j++) {clsSopa::
            letras[i][j] = 0;
        }
    }
 }



 //=============================================================================
// FUNCION : void clsSopa::crearMatrizPosiciones()
// ACCION : Crea la matriz de posiciones y la inicializa con -1
// PARAMETROS:  ()
// DEVUELVE :  void NADA
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void clsSopa::crearMatrizPosiciones() {
    posiciones = new int*[tam];
    for(int i = 0; i < tam; i++) {
        posiciones[i] = new int[tam];
        for(int j = 0; j < tam; j++) {
            posiciones[i][j] = -1;
        }
    }
}
