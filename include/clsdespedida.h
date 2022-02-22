////#############################################################################
// ARCHIVO : clsdespedida.h
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
// metodos de la clase clsdespedida, hereda clsSprite
/////////////////////////////////////////////////////////////////////////////////

#ifndef CLSDESPEDIDA_H
#define CLSDESPEDIDA_H

#include <clsSprite.h>
#include <clsScreen.h>

class clsDespedida : public clsSprite
{
    public:
    void inherit(){};
    int init (const char * path);

    private:
        clsScreen *screen;
};
#endif // CLSDESPEDIDA_H
