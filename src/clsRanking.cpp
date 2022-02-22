////#############################################################################
// ARCHIVO : clsRanking.cpp
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
// Se encarga de manejar el archivo que contendra los mejores puntajes, es decir los
//menores tiempos
/////////////////////////////////////////////////////////////////////////////////
#include "clsRanking.h"


//*****************************************************************************
// DEFINICION DE LOS METODOS
//=============================================================================
// FUNCION : void clsRanking::leerRanking()
// ACCION : lee el archivo de ranking, en caso de que no exista lo crea, lo lee mientras sean 10 o
// no sea el fin del archivo.
// PARAMETROS: ()
// DEVUELVE : void NADA
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void clsRanking::leerRanking() {
    FILE *arch = fopen("ranking.txt", "rt");
    if(!arch) {         // si el archivo no existe lo crea
        arch = fopen("ranking.txt", "wt");
        fclose(arch);
        arch = fopen("ranking.txt", "rt");
    }

    float f;
    int i = 0;
    fscanf(arch, "%f", &f);
    while(i < 10 && !feof(arch)) {
        ranking[i++] = f;
        fscanf(arch, "%f", &f);
    }
    while(i < 10) {
        ranking[i++] = 0;
    }

    fclose(arch);
}

//=============================================================================
// FUNCION : void clsRanking::draw(clsScreen *screen)
// ACCION : se encarga iniciarlo y dibujarlo en pantalla, tambien
// de la personalizacion del timer, ya sea fuente, color etc.
// PARAMETROS: (clsScreen *screen)
// DEVUELVE : void NADA
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void clsRanking::draw(clsScreen *screen) {
    leerRanking();

    screen->clean(BLACK);

    int y = 10;
    int i = 0;
    while(i < 10 && ranking[i] != 0) {
        txt[i].init();
        txt[i].setBackColor(BLACK);
        txt[i].loadFont("FONTS/FreeMono.ttf", 30);
        txt[i].setTexture(SHADED);
        txt[i].setStyle(BOLD);
        txt[i].setFontColor(WHITE);

        char palabra[10];
        sprintf(palabra, "%6.1f s", ranking[i]);   // pasa el float a texto
        txt[i].write(palabra, 30, y, screen->getPtr());
        y += 30;
        i++;
    }

    screen->refresh();
}

//=============================================================================
// FUNCION : int clsRanking::run(clsScreen *screen, clsEvent *event)
// ACCION : es la funcion principal del ranking quien se encargara de arrancarlo, y llamara a
// el metodo que lo dibuje, tambien reconoce los eventos, para salir cuando estemos dentro del ranking
// con la tecla ESC
// PARAMETROS: (clsScreen *screen, clsEvent *event)
// DEVUELVE : int
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int clsRanking::run(clsScreen *screen, clsEvent *event) {
    bool salir = false;

    draw(screen);

    while(!salir) {
        if(event->wasEvent()) {
            salir = event->getEventType() == KEY_PRESSED && event->getKey() == KEY_ESCAPE;
        }
    }
}
//=============================================================================
// FUNCION : void clsRanking::agregarRanking(int milis)
// ACCION : se encarga de guardar el nuevo tiempo
// haciendo un decremento porque van decreciendo y se guardan los menores
// PARAMETROS: (int milis)
// DEVUELVE : void NADA
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void clsRanking::agregarRanking(int milis) {
    leerRanking();

    int i;
    float tiempo = (float)(milis/100) / 10;
    for(i = 0; i < 10 && ranking[i] != 0; i++);

    if(i < 10 || tiempo < ranking[--i]) {
        while(i > 0 && tiempo < ranking[i-1]) {
            ranking[i] = ranking[i-1];
            i--;
        }
        ranking[i] = tiempo;

        guardarRanking();
    }
}

//=============================================================================
// FUNCION : void clsRanking::guardarRanking()
// ACCION : se encarga crear un nuevo archivo de ranking en caso de que no exista.
// PARAMETROS: ()
// DEVUELVE : void NADA
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void clsRanking::guardarRanking() {
    FILE *arch = fopen("ranking.txt", "wt");

    for(int i = 0; i < 10 && ranking[i] != 0; i++) {
        fprintf(arch, "%.1f ", ranking[i]);
    }
    fclose(arch);
}

