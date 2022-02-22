////#############################################################################
// ARCHIVO : clsBoton.h
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
// metodos de la clase boton, hereda clsPresent
/////////////////////////////////////////////////////////////////////////////////

#ifndef CLSBOTON_H
#define CLSBOTON_H
#include <clsPresent.h>

class clsBoton : public clsPresent
{
    public:
        int init(int,int,const char *);

    protected:
        void inherit(){};

    private:
};

#endif // CLSBOTON_H
