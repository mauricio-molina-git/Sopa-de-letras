////#############################################################################
// ARCHIVO : clsBoton.cpp
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
// Se encarga de la carga de los botones que seran utilizados en el menu interactivo
// para asi dirigirnos a nuevas pantallas o volver a otra.
/////////////////////////////////////////////////////////////////////////////////
#include <clsBoton.h>


//*****************************************************************************
// DEFINICION DE LOS METODOS
//=============================================================================
// FUNCION : int clsBoton::init(int x, int y, const char *path)
// ACCION : inicializa los botones, es decir
// Cargo la imagen que sera perteneciente a los botones correspondientes y las cordenadas
// x e y a la que correspondan para ver donde van posicionados, lo divide por 2 para ver si va
// posicionado arriba o abajo.
// PARAMETROS: int x, int y, const char *path
// DEVUELVE : int que puede ser un error error.get()
//-----------------------------------------------------------------------------
int clsBoton::init(int x, int y, const char *path)
{
    error.set(0);  //Inicializo el codigo de error
    setItems(1);   //Indico la cantidad de imagenes que tendra el vector de sprites
    setI(0);       //Indico el indice dentro del vector a colocar la imagen
    error.set(load(path)); //Cargo la imagen
    setX(x-getWidth()/2);
    setY(y);
    if(error.get())return error.get();
}
