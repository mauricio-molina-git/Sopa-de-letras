////#############################################################################
// ARCHIVO : clsRanking.h
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
// metodos y atributos de la clase clsRanking
/////////////////////////////////////////////////////////////////////////////////


#ifndef CLSRANKING_H
#define CLSRANKING_H

#include <clsScreen.h>
#include <clsText.h>
#include <clsEvent.h>


class clsRanking
{
private:
    clsText txt[10];
    void draw(clsScreen *screen);

    float ranking[10];
    void leerRanking();
    void guardarRanking();

public:
    int run(clsScreen *screen, clsEvent *event);
    void agregarRanking(int tiempo);
};

#endif // CLSRANKING_H
