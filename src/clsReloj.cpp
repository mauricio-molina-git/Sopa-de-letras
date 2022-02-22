////#############################################################################
// ARCHIVO : clsReloj.cpp
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
// Dibuja el rejoj, asignando sus propiedades
/////////////////////////////////////////////////////////////////////////////////

#include "clsReloj.h"

//*****************************************************************************
// DEFINICION DE LOS METODOS
//=============================================================================
// FUNCION : void clsReloj::draw(clsScreen *screen)
// ACCION : dibuja el reloj que indica el tiempo que queda de juego
// PARAMETROS: (clsScreen *screen)
// DEVUELVE :  void NADA
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void clsReloj::draw(clsScreen *screen) {
    setFontColor(color);
    write(txt, x, y, screen->getPtr());
}
