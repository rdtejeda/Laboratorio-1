/*
 ============================================================================
 Name        : Sab_Puntero.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/******************************************************************************

Ejercicio 8.2
Realizar una función que reciba un puntero a char y dos char. La función deberá
reemplazar en la cadena cada ocurrencia del primer carácter recibido, por el segundo.
Retornando la cantidad de reemplazos o -1 en caso de error.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ReemplazarCaracteres (char* cadena, int tamanioCadena, char caracterAReemplazar, char caracterQueVaAReemplazar);

int main()
{
    char cadenaDeChars[51] = "sabado";
    /*
    char* p;
    p = cadenaDeChars;
    printf("%d %d", sizeof(p), sizeof(cadenaDeChars));
    */
    int reemplazos;
    reemplazos = ReemplazarCaracteres (cadenaDeChars, sizeof(cadenaDeChars), 'a', 'i');
    printf("Cant. reemplazos: %d\nPalabra reemplazada: %s", reemplazos, cadenaDeChars);

    return 0;
}

int ReemplazarCaracteres (char* cadena, int tamanioCadena, char caracterAReemplazar, char caracterQueVaAReemplazar) {
    int cantidadReemplazos;
    int longitudDeCadena;

    cantidadReemplazos = -1;

    if (cadena != NULL) {
        cantidadReemplazos = 0;
        longitudDeCadena = strnlen(cadena, tamanioCadena);
        for (int i = 0; i < longitudDeCadena; i++) {
            if (*(cadena+i) == caracterAReemplazar)
            {
                *(cadena+i) = caracterQueVaAReemplazar;
                cantidadReemplazos++;
            }
        }
    }
    return cantidadReemplazos;
}
