////#############################################################################
// ARCHIVO : clsMotor.h
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
// metodos  de la clase clsMotor
/////////////////////////////////////////////////////////////////////////////////


#ifndef CLSMOTOR_H
#define CLSMOTOR_H

#include <clsEvent.h>

#include <clsMode.h>
#include <clsScreen.h>
#include <clsError.h>
#include <adnConsts.h>
#include <clsPresent.h>
#include <clsTimer.h>
#include "clsJuego.h"
#include <clsMenu.h>
#include <clsDespedida.h>
class clsMotor
{
protected:
    clsEvent event;
    clsMode mode;
    clsScreen screen;
    clsError error;
    clsPresent presentacion;
    clsDespedida despedida;
    clsMenu menu;
    clsTimer timer;


public:
    int init();
    int run();
    int keyCommand(bool*,Uint16);
};

#endif // CLSMOTOR_H
