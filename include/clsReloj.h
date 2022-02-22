////#############################################################################
// ARCHIVO : clsReloj.h
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
// metodos y atributos de la clase clsReloj, hereda clsText
/////////////////////////////////////////////////////////////////////////////////


#ifndef CLSRELOJ_H
#define CLSRELOJ_H

#include <clsScreen.h>
#include <clsText.h>
#include <adnConsts.h>


class clsReloj : public clsText
{
public:
    int x, y;               // posición en la pantalla
    char txt[20];           // texto del reloj
    rgbColor color;         // color del display

    void draw(clsScreen *screen);
};

#endif // CLSRELOJ_H
