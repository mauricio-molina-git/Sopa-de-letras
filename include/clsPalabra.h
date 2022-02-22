////#############################################################################
// ARCHIVO : clsPalabra.h
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
// metodos y propiedades  de la clase clsPalabra
/////////////////////////////////////////////////////////////////////////////////



#ifndef CLSPALABRA_H
#define CLSPALABRA_H

class clsPalabra
{
public:
    char *palabra;
    int i, j;           // coordenadas de la primera letra en la matriz
    int di, dj;         // direcciones horizontal y vertical (-1, 0, 1)
    int largo;          // largo inicial de la palabra
    int clics;          // letras sin acertar

    int init(char *palabra);

    ~clsPalabra();      // destructor: libera la memoria dinámica de palabra
};

#endif // CLSPALABRA_H
