////#############################################################################
// ARCHIVO : clspresent.cpp
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
// Se encarga de cargar la pantalla de presentacion que luego es usada por el motor
/////////////////////////////////////////////////////////////////////////////////


#include "clsPresent.h"

//*****************************************************************************
// DEFINICION DE LOS METODOS
//=============================================================================
// FUNCION : int clsPresent::init(const char * path)
// ACCION : Carga la pantalla de bienvenida, levanta la imagen a traves del path
// PARAMETROS: const char * path
// DEVUELVE : int , devuelve si existio error error.get();
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int clsPresent::init(const char * path)
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
