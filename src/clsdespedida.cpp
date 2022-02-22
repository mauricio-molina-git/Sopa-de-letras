////#############################################################################
// ARCHIVO : clsdespedida.cpp
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
// Se encarga de la carga de La pantalla de despedida, la cual es una imagen que levanta el path
// Dicha imagen aparecera solo cuando se salga del juego a traves del boton salir en el menu, o apretando
// ESC solo en el menu.
/////////////////////////////////////////////////////////////////////////////////
#include "clsDespedida.h"

//*****************************************************************************
// DEFINICION DE LOS METODOS
//=============================================================================
// FUNCION : int clsDespedida::init(const char * path)
// ACCION : Carga la pantalla de despedida, levanta la imagen a traves del path
// PARAMETROS: const char * path
// DEVUELVE : int , devuelve si existio error error.get();
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int clsDespedida::init(const char * path)
{

    setItems (1);
    setI(0);
    error.set(load(path));

    if(error.get()){

        error.show (true);
        return error.get();
    }
    return error.get();
}
