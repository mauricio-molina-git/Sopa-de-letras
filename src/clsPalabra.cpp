////#############################################################################
// ARCHIVO : clsPalabra.cpp
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
// Inicializa las palabras y la pasa a mayusculas.
/////////////////////////////////////////////////////////////////////////////////

#include "clsPalabra.h"
#include <cstring>

//*****************************************************************************
// DEFINICION DE LOS METODOS
//=============================================================================
// FUNCION : char *strUpr(char *pal)
// ACCION : convierte las letras a mayuscula
// PARAMETROS: (*pal)
// DEVUELVE : char * pal;
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
char *strUpr(char *pal) {
    for(int i = 0; pal[i] != 0; i++) {
        if(pal[i] >= 'a' && pal[i] <= 'z') {
            pal[i] -= 32;
        }
    }
    return pal;
}

//=============================================================================
// FUNCION : int clsPalabra::init(char *palabra)
// ACCION : Inicializa la palabra, con su largo
// PARAMETROS: (*pal)
// DEVUELVE : int 0
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int clsPalabra::init(char *palabra) {
    clics = largo = strlen(palabra);
    this->palabra = new char[largo + 1];
    strcpy(this->palabra, palabra);
    strUpr(this->palabra);
    return 0;
}


//=============================================================================
// FUNCION : clsPalabra::~clsPalabra()
// ACCION : libera la memoria
// PARAMETROS: ()
// DEVUELVE :
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
clsPalabra::~clsPalabra() {
    delete palabra;
}


