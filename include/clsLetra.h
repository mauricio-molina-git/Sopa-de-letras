////#############################################################################
// ARCHIVO : clsLetra.h
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
// metodos y propiedades de la clase clsLetra, hereda de clsText
/////////////////////////////////////////////////////////////////////////////////

#ifndef CLSLETRA_H
#define CLSLETRA_H

#include <clsScreen.h>
#include <clsText.h>
#include <adnConsts.h>

class clsLetra : public clsText
{
public:
    int x, y;               // posición en la pantalla
    char txt[2];            // forma un string de una sola letra

    void draw(clsScreen *screen, rgbColor color);
};

#endif // CLSLETRA_H
