////#############################################################################
// ARCHIVO : clsMenu.h
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
// metodos  de la clase clsMenu
/////////////////////////////////////////////////////////////////////////////////

#ifndef CLSMENU_H
#define CLSMENU_H
#include <clsScreen.h>
#include <clsEvent.h>
#include <clsError.h>
#include <clsPresent.h>
#include <clsBoton.h>
#include <clsTimer.h>
#include <clsDespedida.h>
#include "clsJuego.h"
#include "clsRanking.h"

class clsMenu
{
    private:
        clsScreen *screen;
        clsEvent *event;
        clsError error;
        clsPresent fondo,fondoayuda;
        clsDespedida despedida;
        clsBoton btnSalir, btnJugar, btnAyuda, btnNiveles, btnRanking, btnsalirayuda;
        clsJuego juego;
        clsTimer timer;
        clsRanking ranking;

        int keyCommand(bool*,Uint16);
        void draw();
        bool clic(clsBoton &boton);

    public:
        int init(clsScreen *, clsEvent *);
        int run();
        void menuAyuda();
        void menuranking();
};
#endif // CLSMENU_H
