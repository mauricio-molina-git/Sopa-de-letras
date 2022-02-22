////#############################################################################
// ARCHIVO : clsMenu.cpp
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
// Se encarga de colocar las imagenes y botones que pertenecen al menu interactivo, asi tambien como
// de controlar los eventos de este mismo, ya sea el ingreso a una determinada opcion
/////////////////////////////////////////////////////////////////////////////////

#include "clsMenu.h"

//*****************************************************************************
// DEFINICION DE LOS METODOS
//=============================================================================
// FUNCION : int clsMenu::init(clsScreen *screen, clsEvent *event)
// ACCION : se encarga de cargar las imagenes y botones del menu
// PARAMETROS: (clsScreen *screen, clsEvent *event)
// DEVUELVE :  int si hubo error
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int clsMenu::init(clsScreen *screen, clsEvent *event)
{
    error.set(0);
    this->screen=screen;
    this->event=event;
    error.set(fondo.init("IMAGENES/fondo.png"));
    if(error.get()){
        error.show(true);
        return error.get();
    }

    error.set(btnJugar.init(400,180,"IMAGENES/Jugar.png"));
    if(error.get()){
        error.show(true);
        return error.get();
    }
    error.set(btnSalir.init(700,520,"IMAGENES/SALIR.png"));
    if(error.get()){
        error.show(true);
        return error.get();
    }
        error.set(btnAyuda.init(100,520,"IMAGENES/AYUDA.png"));
    if(error.get()){
        error.show(true);
        return error.get();
    }
    error.set(btnRanking.init(400,300,"IMAGENES/RANKING.png"));
    if(error.get()){
        error.show(true);
        return error.get();
    }

    error.set(despedida.init("IMAGENES/adios.png"));
    if(error.get()){
        error.show(true);
        return error.get();
    }

    error.set(fondoayuda.init("IMAGENES/fondoayuda.png"));
    if(error.get()){
        error.show(true);
        return error.get();
    }
}
//=============================================================================
// FUNCION : void clsMenu::draw()
// ACCION : se encarga de colocar las imagenes y botones del menu en su cordenada correspondiente
// PARAMETROS: ()
// DEVUELVE :  void NADA
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void clsMenu::draw() {
    screen->clean(BLACK);
    fondo.paste(screen->getPtr());
    btnJugar.paste(screen->getPtr());
    btnSalir.paste(screen->getPtr());
    btnAyuda.paste(screen->getPtr());
    btnRanking.paste(screen->getPtr());
    screen->refresh();
}

//=============================================================================
// FUNCION : bool clsMenu::clic(clsBoton &boton)
// ACCION : se encarga de detectar la interaccion con los botones
// PARAMETROS: (clsBoton &boton)
// DEVUELVE :  bool
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
bool clsMenu::clic(clsBoton &boton) {
    int x = event->getCursorX();
    int y = event->getCursorY();

    return
        x >= boton.getX() &&
        x <= boton.getX() + boton.getWidth() &&
        y > boton.getY() &&
        y < boton.getY() + boton.getHeight();
}

//=============================================================================
// FUNCION : int clsMenu::run()
// ACCION : se encarga de todo el funcionamiento del menu, la deteccion de eventos sobre los botones como la tecla ESC
// cuando se presione sobre el boton que precisa el usuario, se llamara a la rutina que lo ejecute
// PARAMETROS: ()
// DEVUELVE :  int, si hay error
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int clsMenu::run(){
    draw();
    bool salir = false;
    while(!salir) {
        if(event->wasEvent())  //Verifico si hay evento
        {
            if(event->getEventType() == KEY_PRESSED) {
                salir = event->getKey() == KEY_ESCAPE;
            } else if(event->getEventType() == MOUSE_DOWN && event->getMouseButton() == MOUSE_LEFT_BUTTON) {
                if(clic(btnSalir)) {
                    salir = true;
                } else if(clic(btnJugar)) {
                    error.set(juego.init("palabras.txt"));  //Inicio el juego
                    if(error.get())return error.get();

                    juego.run(screen, event);
                    draw();
                } else if(clic(btnAyuda)) {
                    menuAyuda();
                    draw();
                } else if(clic(btnRanking)) {
                    ranking.run(screen, event);
                    draw();
                }
            }
        }
    }
}

//=============================================================================
// FUNCION : void clsMenu::menuAyuda()
// ACCION : se encarga de controlar el menu de ayuda, de pegar la imagen que indica como se juega, de pegar el boton de salir
// una vez que ya estamos dentro de esta pantalla, y de detectar los eventos que interactuan con la ayuda.
// PARAMETROS: ()
// DEVUELVE : void NADA
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void clsMenu::menuAyuda() {
    bool salir = false;

    fondoayuda.paste(screen->getPtr());
    btnSalir.paste(screen->getPtr());
    screen->refresh();

    while (!salir){
        if(event->wasEvent()) {
            if(event->getEventType() == KEY_PRESSED) {
                salir = event->getKey() == KEY_ESCAPE;
            } else if(event->getEventType() == MOUSE_DOWN && event->getMouseButton() == MOUSE_LEFT_BUTTON) {
                salir = clic(btnSalir);
            }
        }
    }
}
