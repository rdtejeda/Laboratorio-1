/*
 ============================================================================
 Name        : Parcial_1_14Octubre_2021.c
 Author      : Tejeda Roberto
 Version     : 1.1
 Copyright   : Your copyright notice
 Description : Estamos en el año 1990!
 ============================================================================
 */
/*
 *
1) LEER ARCADES DESDE ARCHIVO CSV
Se lee de archivo arcades.csv provisto, la lista de arcades del sistema, y se cargan en una LinkedLIst.
2) INCORPORAR ARCADE
Se da de alta un arcade con la nacionalidad, tipo de sonido, cantidad de jugadores, capacidad máxima de
fichas, Nombre del salón al que pertenece y nombre del juego que contiene (hasta 63 caracteres).
Se generará un ID único para gestionar los ARCADE. Actualizar el archivo CSV con el arcade agregado
3) MODIFICAR ARCADE
Se imprime la lista de arcades con los ID y datos que lo componen.
Se pide que se ingrese un ID y se pueda modificar los campos cantidad de jugadores o juego que contiene.
Al elegir modificar el juego que contiene este arcade, mostrar en un listado los nombres de los juegos ya
cargados en el sistema y se permitirá ingresar un texto con el nombre del nuevo juego. Actualizar el archivo CSV con
el arcade modificado.
4) ELIMINAR ARCADE
Se imprime la lista de arcades con sus ID y datos que lo componen, junto con la información del salón y el
juego que contiene.
Se ingresa un ID y previo a dar de baja se deberá solicitar confirmación, imprimiendo el arcade a dar de baja y
confirmando si está seguro dar de baja esté mismo. Actualizar el archivo CSV con el arcade aeliminado.
5) IMPRIMIR ARCADES
ordenados por nombre de juego Se imprime la lista de arcades con ID, y sus datos.
6) Generar archivo con JUEGOS
Se generará un archivo .txt con los nombres de los juegos (uno por linea) sin repetir.
7) Generar un archivo con arcades “Multijugador” (mas de 1 jugador)
Se generará un archivo “multijugador.csv” con el mismo formato que arcades.csv (incluida la cabecera), que
contenga solo los arcades que tengan mas de 1 jugador.
8) Actualizar cantidad de fichas
La empresa compró una actualizacion para que los arcades soporten el doble de fichas, por lo que debe
actualizarse el valor de fichas en el archivo. Al elegir esta opcion, se duplicará el valor de cantidad de fichas de todos
los arcades.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#include "LinkedList.h"//
#include "controller.h"//
#include "arcade.h"//
#include "parser.h"//
#include "pedirValidar.h"//
#include "Menu.h"//
#include "Juego.h"//

#define MINIMO 1
#define MAXIMO10 10
#define INTENTOS 3

/**
* \brief Imprime el encabezado de la lista de arcade
* \param
* \return
*/
void imprimirEncArcadeCargado()
{
	printf("____________________________________________________________________________________________________________\n");
	printf("Id     Nacionalidad                Sonido    Jugadores  Max.Fichas Salon                  Juego\n");
	printf("____________________________________________________________________________________________________________\n");
}
/**
* \brief Imprime el encabezado de la lista de arcade
* \param
* \return
*/
void imprimirJuegoCargado()
{
	printf("__________________________________\n");
	printf(" Juego\n");
	printf("__________________________________\n");
}
/**
* \brief Imprime una linea
* \param
* \return
*/
void imprimirLinea()
{
	printf("____________________________________________________________________________________________________________\n");
}
/**
* \brief Imprime el menu de INICIAL de opciones
* \param
* \return
*/
int imprimirMenuInicial()
{
	int opcion;
	puts("MENU PRINCIPAL");
	puts("1- INCORPORAR ARCADE");
	puts("2- MODIFICAR ARCADE");
	puts("3- ELIMINAR ARCADE");
	puts("4- IMPRIMIR ARCADES");
	puts("5- Generar archivo con JUEGOS");
	puts("6- Generar un archivo con arcades “Multijugador” (mas de 1 jugador)");
	puts("7- Actualizar cantidad de fichas");
	puts("8- Grabar Lista Arcade");
	//puts("9- INFORMES");
	puts("10- SALIR");
	pedirInt(&opcion,"Ingese la opción deseada","ERROR-Ingrese Opcion entre 1y7-Para Salir 10",MINIMO,MAXIMO10,INTENTOS);
return opcion;
}
/**
  * \brief imprime el menu de edicion, pide la opcion deseada
  * \param void
  * \return Retorna opcion deseada si todo bien  y -1 si no lo logra
  */
int menuOpcion()
{
	int opcion=-1;
puts("****************************************************************************");
puts("Elija Opcion:");
puts("1. Nombre Juego");
puts("2. Cantidad de Jugadores");
puts("3. Salir");
puts("******************************************************************************");
pedirInt(&opcion,"Seleccione dato a modificar","Error-Imgrese entre 1 y 3",MINIMO,INTENTOS,INTENTOS);
return opcion;
}
/**
* \brief Imprime el menu de informes
* \param
* \return
*/
void imprimirMenuInformes()
{
	puts("A) Listar los salones con más de 4 arcades. Indicando ID de salón, nombre, dirección y tipo de salón.");
	puts("B) Listar los arcades para más de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del juego y nombre del salón al que pertenece.");
	puts("C) Listar toda la información de un salón en específico ingresando su ID. Imprimir nombre, tipo y dirección y cantidad de arcades que posee.");
	puts("D) Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre y tipo de salón, listar todos los arcades con sus datos junto con el nombre del juego que lo compone.");
	puts("E) Imprimir el salón con más cantidad de arcades, indicando todos los datos del salón y la cantidad de arcades que posee.");
	puts("F) Ingresar el ID de un salón, y el valor en pesos de una ficha, e imprimir el monto máximo en pesos que puede recaudar el salón (sumar cantidad de fichas máximo de cada arcade del salón y multiplicarla por el valor en pesos ingresado)");
	puts("G) Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen.");
	puts("H) Un salón se encuentra equipado por completo si posee al menos 8 arcades de mas de 2 jugadores. Listar los salones que cumplan con este mínimo de requisito.");
	puts("I) Imprimir el promedio de arcades por salón. (Cantidad de arcades totales / Cantidad de salones totales");
	puts("J) SALIR DE INFORMES");
}
/**
* \brief Imprime el menu de modificacion
* \param
* \return
*/
void imprimirMenuModificar()
{
	puts("1- Cantidad de jugadores");
	puts("2- Juego que contiene");
	puts("3- SALIR");
}
/**
* \brief Imprime el encabezado de la lista de salones
* \param
* \return
*/
void imprimirEncSalonCargado()
{
	printf("______________________________________________________________________________________________\n");
	printf("\nNombre del Salon\t\tDirección\t\t\tTipo de Salon\tId Salon\n");
	printf("______________________________________________________________________________________________\n");
}
