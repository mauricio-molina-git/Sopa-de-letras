////#############################################################################
// ARCHIVO : clsJuego.cpp
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
// Se encarga de manejar los eventos del juego, asi como de dibujar la sopa de letras, el timer y
// de controlar los estados, tanto del relog como del juego, si gano o perdio. tambien crear
// el vector de palabras dinamico.
/////////////////////////////////////////////////////////////////////////////////

#include "clsJuego.h"

#include <cstdio>
#include <cstring>

//*****************************************************************************
// DEFINICION DE LOS METODOS
//=============================================================================
// FUNCION : int clsJuego::init(const char *nomArch)
// ACCION : Es una de las funciones mas importantes del sistema, se encarga de leer el archivo que
// contiene las palabras que integraran la sopa de letras y cuenta las palabras existentes, luego crea dinamicamente
// un vector para esa cantidad de palabras
// volvemos a leer el archivo desde el comienzo y  basandose en la palabra mas larga copiamos las palabras,
// asi nos aseguramos de que entren todas en la tabla ,,copiamos cada palabra del archivo en el vector.
// se inicializa la sopa mandandole el vector y la cantidad de palabras.
// tambien esta funcion coontiene las imagenes de ganaste y perdiste
// PARAMETROS: (const char *nomArch)
// DEVUELVE : int , devuelve si existio error.
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int clsJuego::init(const char *nomArch) {
    FILE *arch = fopen(nomArch, "rt");
    if(!arch) {
        return 1;   // retorna un código de error
    }
    char palabra[50];
    int cant = 0;

    // lee todo el archivo para contar las palabras
    fscanf(arch, "%s", palabra);
    while(!feof(arch)) {
        cant++;
        fscanf(arch, "%s", palabra);
    }
    // crea dinámicamente un vector para esa cantidad de palabras
    char **lista = new char*[cant];
    // reinicia el srchivo
    rewind(arch);
    // copia cada palabra del archivo en el vector de palabras
    for(int i = 0; i < cant; i++) {
        fscanf(arch, "%s", palabra);
        int largo = strlen(palabra);
        lista[i] = new char[largo + 1];
        strcpy(lista[i], palabra);
    }
    // cierra el srchivo
    fclose(arch);
    // inicia la sopa con la lista de palabras
    sopa.init(lista, cant);
    this->tam = sopa.getTam();
    // finalmente libera la memoria de la lista
    for(int i = 0; i < cant; i++) {
        delete lista[i];
    }
    delete lista;

    error.set(ganaste.init("IMAGENES/ganaste.png"));
    if(error.get()){
        error.show(true);
        return error.get();
    }
    error.set(perdiste.init("IMAGENES/perdiste.png"));
    if(error.get()){
        error.show(true);
        return error.get();
    }


    return 0;
}

//=============================================================================
// FUNCION : void clsJuego::draw(clsScreen *screen) {
// ACCION : Se encarga de dibujar la sopa de letras, es decir la matriz, x e y trabajan con las cordenadas graficas.
// i  e j con las cordenadas logicas, inicializan las letras, con su tipo de fuente, color estilo.
// Asi mismo se encarga de dibujar en pantalla el reloj que va a ir indicando cuanto tiempo resta de juego,
// para ello se le asigna
// una cordenada en pantalla que no afecte al juego, y sus propiedas, sea color fuente estilo.
// cada casillero tiene 30 x 30
// PARAMETROS: (clsScreen *screen)
// DEVUELVE : void NADA
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void clsJuego::draw(clsScreen *screen) {
    x0 = (screen->getWidth() - tam * 30) / 2;
    y0 = (screen->getHeight() - tam * 30) / 2;

    letras = new clsLetra*[tam];

    screen->clean(BLACK);

    int y = y0;
    for(int i = 0; i < tam; i++) {
        letras[i] = new clsLetra[tam];
        int x = x0;
        for(int j = 0; j < tam; j++) {
            letras[i][j].init();
            letras[i][j].setBackColor(BLACK);
            letras[i][j].loadFont("FONTS/FreeMono.ttf", 30);
            letras[i][j].setTexture(SHADED);
            letras[i][j].setStyle(BOLD);
            letras[i][j].txt[0] = sopa.get(i, j);
            letras[i][j].txt[1] = 0;
            letras[i][j].x = x;
            letras[i][j].y = y;
            letras[i][j].draw(screen, WHITE);
            x += 30;
        }
        y += 30;
    }

    reloj.setBackColor(BLACK);
    reloj.loadFont("FONTS/FreeMono.ttf", 30);
    reloj.setTexture(SHADED);
    reloj.setStyle(BOLD);
    reloj.color = YELLOW;

    reloj.x = 30;
    reloj.y = 10;
    strcpy(reloj.txt, "0");
    reloj.draw(screen);

    screen->refresh();
}

//=============================================================================
// FUNCION : int clsJuego::run(clsScreen *screen, clsEvent *event)
// ACCION : se encarga de manejar el estado de juego, ya sea el tiempo que va desde que inicio la partida, el tiempo
// extra que se le suma por partida encontrada , como tambien si gano la partida o perdio
// tambien se encarga de guardar el ranking solo cuando se gana, y maneja los eventos.
// PARAMETROS: (clsScreen *screen, clsEvent *event)
// DEVUELVE : int resultado
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int clsJuego::run(clsScreen *screen, clsEvent *event) {
    draw(screen);

    bool salir = false;
    Resultado resultado = eNada;
    timer.start();

  limite = 120000;
    int milis;

    while(!salir)  //Ciclo del juego
    {
        milis = timer.getState();

        sprintf(reloj.txt, "%d / %d", milis / 1000, limite / 1000);
        reloj.draw(screen);
        screen->refresh();

        if(milis > limite) {
            salir = true;
        } else if(event->wasEvent()) {
            if(event->getEventType() == KEY_PRESSED) {
                salir = event->getKey() == KEY_ESCAPE;
            } else if(event->getEventType() == MOUSE_DOWN && event->getMouseButton() == MOUSE_LEFT_BUTTON) {
                resultado = mouseEvent(screen, event);
                switch(resultado) {
                case ePalabra:
                    limite += 20000;
                    break;
                case eJuego:
                    salir = true;
                    break;
                }
            }
        }
    }

    if(resultado == eJuego) {
        ranking.agregarRanking(milis);
    ganaste.paste(screen->getPtr());
    screen->refresh();
    timer.wait(3000);
    }
     else {
        // Perdiste
    perdiste.paste(screen->getPtr());
    screen->refresh();
    timer.wait(3000);
    }

    return resultado;
}

//=============================================================================
// FUNCION : Resultado clsJuego::mouseEvent(clsScreen *screen, clsEvent *event)
// ACCION : se encarga de los eventos de mouse, es decir de pintar las letras cuando se encuentra una palabra
// o pintar la palabra entera cuando se la marca por completo
// PARAMETROS: (clsScreen *screen, clsEvent *event)
// DEVUELVE :  resultado
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
Resultado clsJuego::mouseEvent(clsScreen *screen, clsEvent *event) {
    int mx = event->getCursorX() - x0;
    int my = event->getCursorY() - y0;
    clsPalabra *palabra;

    if(mx < 0 || my < 0) {
        return eNada;
    }

    int i = my / 30;
    int j = mx / 30;

    if(j >= tam || i >= tam) {
        return eNada;
    }

    Resultado resultado = sopa.clic(i, j, &palabra);

    switch(resultado) {
    case eLetra:
        letras[i][j].draw(screen, ORANGE);
        screen->refresh();
        break;
    case eJuego:
    case ePalabra:
        completarPalabra(screen, palabra);
        break;
    }

    return resultado;
}

//=============================================================================
// FUNCION : void clsJuego::completarPalabra(clsScreen *screen, clsPalabra *palabra)
// ACCION : se encarga de detectar cuando se completa una palabra y la pinta toda de verde
// PARAMETROS: (clsScreen *screen, clsPalabra *palabra)
// DEVUELVE :  void nada
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void clsJuego::completarPalabra(clsScreen *screen, clsPalabra *palabra) {
    int i = palabra->i;
    int j = palabra->j;
    int di = palabra->di;
    int dj = palabra->dj;
    int largo = palabra->largo;

    for(int p = 0; p < largo; p++) {
        letras[i][j].draw(screen, GREEN);
        i += di;
        j += dj;
    }
    screen->refresh();
}
