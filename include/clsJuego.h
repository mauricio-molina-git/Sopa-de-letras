////#############################################################################
// ARCHIVO : clsJuego.h
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
// metodos y propiedades de la clase clsJuego
/////////////////////////////////////////////////////////////////////////////////

#ifndef CLSJUEGO_H
#define CLSJUEGO_H

#include <clsError.h>
#include <clsScreen.h>
#include <clsText.h>
#include <clsEvent.h>
#include <clsTimer.h>

#include "clsSopa.h"
#include "clsLetra.h"
#include "clsPalabra.h"
#include "clsReloj.h"
#include "clsRanking.h"
#include "clspresent.h"
class clsJuego
{
private:
    clsError error;
    clsSopa sopa;
    clsLetra **letras;
    clsTimer timer;
    clsReloj reloj;
    clsRanking ranking;
    clsPresent ganaste,perdiste;
    int tam;

    int x0, y0;
    void completarPalabra(clsScreen *screen, clsPalabra *palabra);
    void draw(clsScreen *screen);
    int limite;

public:
    int init(const char *nomArch);
    int run(clsScreen *screen, clsEvent *event);
    Resultado mouseEvent(clsScreen *screen, clsEvent *event);

};

#endif // CLSJUEGO_H
