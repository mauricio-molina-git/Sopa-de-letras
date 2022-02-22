////#############################################################################
// ARCHIVO : clsLetra.cpp
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
// Dibuja las letras pertenecientes a la sopa, con sus dichas propiedades
/////////////////////////////////////////////////////////////////////////////////


#include "clsLetra.h"

//*****************************************************************************
// DEFINICION DE LOS METODOS
//=============================================================================
// FUNCION : void clsLetra::draw(clsScreen *screen, rgbColor color)
// ACCION : coloca las letras sobre la superficie
// PARAMETROS: (clsScreen *screen, rgbColor color)
// DEVUELVE :  void NADA
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void clsLetra::draw(clsScreen *screen, rgbColor color) {
    setFontColor(color);
    write(txt, x, y, screen->getPtr());
}
