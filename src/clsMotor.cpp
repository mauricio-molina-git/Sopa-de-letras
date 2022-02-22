////#############################################################################
// ARCHIVO : clsMotor.cpp
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
// Se encarga de inicializar la pantalla en su resolucion por defecto, de cargar las imagenes de bienvenida y de
// despedida, inicializa el menu y detectiva la tecla ESC
/////////////////////////////////////////////////////////////////////////////////


#include "clsMotor.h"

//*****************************************************************************
// DEFINICION DE LOS METODOS
//=============================================================================
// FUNCION : int clsMotor::init()
// ACCION : Inicializa el modo grafico y arranca la pantalla en resolucion por defecto.
// carga las imagenes de despedida y bienvenida.
// PARAMETROS: ()
// DEVUELVE : int, si hay un error
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int clsMotor::init()
{
    error.set(0);
    error.set(mode.init(DEFAULT)); //Inicio el modo grafico
    if(error.get())return error.get();

    error.set(screen.init(mode.getScrWidth(),   //Inicio la pantalla
                          mode.getScrHeight(),
                          mode.getScrDepth(),
                          ENABLED,
                          RESIZABLE));
    if(error.get())return error.get();
    //Init presentacion
    error.set(presentacion.init("IMAGENES/sopadeletras.png"));
    if(error.get()){
        error.show(true);
        return error.get();
    }
    //INIT DESPEDIDA
    error.set(despedida.init("IMAGENES/adios.png"));
    if(error.get()){
        error.show(true);
        return error.get();
    }

    //INIT MENU
    error.set(menu.init(&screen,&event));
    if(error.get()){
        error.show(true);
        return error.get();
    }

    return error.get();
}

//=============================================================================
// FUNCION : int clsMotor::run()
// ACCION : carga la pantallas de bienvenida y de salida y tienen 3 segundos luciendose.
// arranca el menu, que se encargara de manejar el juego, independientemente del motor.
// PARAMETROS: ()
// DEVUELVE : int, si hay un error
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int clsMotor::run()
{
    //ARRANCA LA PRESENTACION
    presentacion.paste(screen.getPtr());
    screen.refresh();
    timer.wait(3000);

    //ARRANCAMOS EL MENU
    menu.run();

    //ARRANCA LA DESPEDIDA
    despedida.paste(screen.getPtr());
    screen.refresh();
    timer.wait(3000);

    return error.get();
}

//=============================================================================
// FUNCION : int clsMotor::keyCommand(bool*salir,Uint16 key)
// ACCION : funcion para detectar la tecla escape y asi salir del sistema
// PARAMETROS: (bool*salir,Uint16 key)
// DEVUELVE : int, si hay un error
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int clsMotor::keyCommand(bool*salir,Uint16 key)
{
    error.set(0);
    switch(key)
    {
    case KEY_ESCAPE:  //Si se preciona escape termino el programa
    {
        *salir = true;
    }
    break;
    }
    return error.get();
}
